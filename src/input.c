#include "globals.h"
#include "types.h"
#include "input.h"

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

/// For windows
#if defined(_WIN32) || defined(_WIN64) || defined(WIN32) || defined(WIN64)

#include <windows.h>

static HANDLE hstdin;
static DWORD stdin_mode_old, stdin_mode_new;

void enable_raw_mode()
{
    // Get the standard input handle.

    hstdin = GetStdHandle(STD_INPUT_HANDLE);
    if (hstdin == INVALID_HANDLE_VALUE)
        fprintf(stderr, "GetStdHandle");

    // Save the current input mode, to be restored on exit.
    if (!GetConsoleMode(hstdin, &stdin_mode_old))
        fprintf(stderr, "GetConsoleMode old");

    stdin_mode_new &= ENABLE_LINE_INPUT;
    if (! SetConsoleMode(hstdin, stdin_mode_new) )
    {
        fprintf(stderr, "SetConsoleMode new");
        exit(0);
    }
}

void disable_raw_mode()
{
    if (! SetConsoleMode(hstdin, stdin_mode_old) )
    {
        fprintf(stderr, "SetConsoleMode old");
        exit(0);
    }
}

#else /// For linux

#include <termios.h>
#include <unistd.h>

static struct termios new_termios, orig_termios;

void enable_raw_mode()
{
    tcgetattr(STDIN_FILENO, &orig_termios);

    new_termios = orig_termios;
    new_termios.c_lflag &= ~(ECHO | ICANON);

    tcsetattr(STDIN_FILENO, TCSAFLUSH, &new_termios);
}

void disable_raw_mode()
{
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &orig_termios);
}

#endif //! end

void *direction_thread(void *arg)
{
    /// Enable raw mode
    enable_raw_mode();

    enum INPUT_KEY key = NONE;

    while (1)
    {
        /// Read key
        fread(&key, sizeof(char), 1, stdin);

        switch (key)
        {
        /// Directional keys
        case UP:
            if (CURRENT_STATE == PLAYING && CURRENT_DIRECTION != DOWN)
                CURRENT_DIRECTION = UP;
            break;
        case DOWN:
            if (CURRENT_STATE == PLAYING && CURRENT_DIRECTION != UP)
                CURRENT_DIRECTION = DOWN;
            break;
        case LEFT:
            if (CURRENT_STATE == PLAYING && CURRENT_DIRECTION != RIGHT)
                CURRENT_DIRECTION = LEFT;
            break;
        case RIGHT:
            if (CURRENT_STATE == PLAYING && CURRENT_DIRECTION != LEFT)
                CURRENT_DIRECTION = RIGHT;
            break;

        /// State keys
        case START:
            if (CURRENT_STATE == MENU)
                CURRENT_STATE = PLAYING;
            break;
        case QUIT:
            if (CURRENT_STATE == PAUSED)
                CURRENT_STATE = GAME_OVER;
            else if(CURRENT_STATE != PLAYING)
                CURRENT_STATE = GAME_QUIT;
            break;
        case PAUSE:
            if (CURRENT_STATE == PLAYING)
                CURRENT_STATE = PAUSED;
            else if(CURRENT_STATE == PAUSED)
                CURRENT_STATE = PLAYING;
            break;
        case RESTART:
            if (CURRENT_STATE == PAUSED || CURRENT_STATE == GAME_OVER)
                CURRENT_STATE = MENU;
            break;
        
        /// Unrecognized keys
        default:
            break;
        }

        /// Exit thread if user quits
        if (CURRENT_STATE == GAME_QUIT) break;
    }

    /// Restore terminal state
    disable_raw_mode();

    return NULL;
}