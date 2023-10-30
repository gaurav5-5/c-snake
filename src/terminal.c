#include "terminal.h"

#include "macros.h"
#include "vmath.h"
#include "enums.h"

#include <stdio.h>
#include <stdlib.h>

#if WIN_CHK
#include <windows.h>
#else
#include <unistd.h>
#include <termios.h>
#include <sys/ioctl.h>
#endif

void 
toggle_raw_mode()
{
    static char raw_mode = 0;
    
    #if WIN_CHK
    static HANDLE hstdin;
    static DWORD stdin_mode_old, stdin_mode_new;    
    #else
    static struct termios term_old, term_new;
    #endif

    if (!raw_mode)
    {
            
        printf("\e[?25l");
        printf("\e[?1049h");

    #if WIN_CHK


        // Get the standard input handle.
        hstdin = GetStdHandle(STD_INPUT_HANDLE);
        if (hstdin == INVALID_HANDLE_VALUE)
            fprintf(stderr, "GetStdHandle");

        // Save the current input mode, to be restored on exit.
        if (!GetConsoleMode(hstdin, &stdin_mode_old))
            fprintf(stderr, "GetConsoleMode old");

        stdin_mode_new &= ENABLE_LINE_INPUT;
        if (!SetConsoleMode(hstdin, stdin_mode_new))
        {
            fprintf(stderr, "SetConsoleMode new");
            exit(0);
        }

    #else

        tcgetattr(STDIN_FILENO, &term_old);

        term_new = term_old;
        term_new.c_lflag &= ~(ECHO | ICANON);

        tcsetattr(STDIN_FILENO, TCSAFLUSH, &term_new);


    #endif
        raw_mode = 1;

    } else {

    #if WIN_CHK

        if (!SetConsoleMode(hstdin, stdin_mode_old))
        {
            fprintf(stderr, "SetConsoleMode old");
            exit(0);
        }

    #else

        tcsetattr(STDIN_FILENO, TCSAFLUSH, &term_old);

    #endif 
    
        printf("\e[?25h"); // show cursor
        printf("\e[?1049l"); // restore screen

        raw_mode = 0;
    }


}

vec2i 
get_term_size()
{
    vec2i size = {0, 0};

    #if WIN_CHK

    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    size.x = csbi.dwSize.X;
    size.y = csbi.dwSize.Y;

    #else

    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    size.x = w.ws_col;
    size.y = w.ws_row;

    #endif

    return size;
}

void
set_term_color(COLOR fg, COLOR bg, vec2i *cell)
{
    if(cell == NULL) 
    {
        printf("\033[%d;%dm", fg, fg2bg(bg));
    } else {
        printf("\033[%d;%d;%d;%dm", cell->x, cell->y, fg, fg2bg(bg));
    }
}

COLOR
fg2bg(COLOR fg)
{
    return ((COLOR)(fg + 10));
}

TPixel
border_pixel(char pos)
{
    TPixel pixel = {0, 0, 0};

    if(pos != 'b')
    {
        pixel.fg = GREEN;
        pixel.bg = BLACK;
    }

    switch(pos)
    {
        case 'h':
            pixel.c = '-';
            break;

        case 'v':
            pixel.c = '|';
            break;

        case 'c':
            pixel.c = '+';
            break;

        case 'b':
        default:
            pixel = blank_pixel();
            break;
    }

    return pixel;
}

TPixel
snake_pixel()
{
    TPixel pixel = {CYAN, BLACK, 'O'};
    return pixel;
}

TPixel
food_pixel()
{
    TPixel pixel = {RED, BLACK, 'X'};
    return pixel;
}

TPixel
blank_pixel()
{
    TPixel pixel = {WHITE, BLACK, ' '};
    return pixel;
}