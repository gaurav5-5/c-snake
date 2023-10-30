#include "input.h"

#include "macros.h"
#include "enums.h"
#include "terminal.h"
#include "game.h"
#include "snake.h"

#include <stdio.h>
#include <stdlib.h>

// Thread function for input
void *input_thread(void * arg)
{
    toggle_raw_mode();
    atexit(toggle_raw_mode);

    
    Game **game_p = (Game **)arg;


    while (1)
    {
        Game *game = *game_p;
        Snake *snake = game->player;

        char key;

        fread(&key, sizeof(char), 1, stdin);
        game->input = (INPUT_KEY)key;

        switch(game->state)
        {
        case MENU:
            switch (key)
            {
            case START:
                game->state = PLAYING;
                break;
            case QUIT:
                game->state = GAME_QUIT;
                break;
            default:
                break;
            }
            break;

        case PLAYING:
            switch (key)
            {
            case UP:
                if(snake->direction != DOWN)
                    snake->direction = UP;
                break;
            case DOWN:
                if(snake->direction != UP)
                    snake->direction = DOWN;
                break;
            case LEFT:
                if(snake->direction != RIGHT)
                    snake->direction = LEFT;
                break;
            case RIGHT:
                if(snake->direction != LEFT)
                    snake->direction = RIGHT;
                break;
            case PAUSE:
                game->state = PAUSED;
                break;
            case QUIT:
                game->state = GAME_QUIT;
                break;
            default:
                break;
            }
            break;
        
        case PAUSED:
            switch (key)
            {
            case PAUSE:
                game->state = PLAYING;
                break;
            case QUIT:
                game->state = GAME_OVER;
                break;
            case RESTART:
                game->state = MENU;
                break;
            default:
                break;
            }
            break;

        case GAME_OVER:
            switch (key)
            {
            case RESTART:
                game->state = MENU;
                break;
            case QUIT:
                game->state = GAME_QUIT;
                break;
            default:
                break;
            }
            break;

        default:
            break;
        }

        if (game->state == GAME_QUIT) break;

    }

    return NULL;
}