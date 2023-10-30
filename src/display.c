#include "display.h"

#include "macros.h"
#include "vmath.h"
#include "game.h"
#include "enums.h"
#include "terminal.h"

#include <stdlib.h>
#include <stdio.h>

// Display constructor
GMdisplay*
GMd_new(void)
{
    GMdisplay *disp = malloc(sizeof(GMdisplay));
    if(disp == NULL) {
        perror("GMd_new");
        exit(EXIT_FAILURE);
    }

    vec2i term_size = get_term_size();

    disp->rows = disp->cols = 30;

    disp->game = NULL;

    return disp;
}

// links a game to a display
void
link_game(GMdisplay *disp, Game *game)
{
    if(disp == NULL || game == NULL) {
        return;
    }

    disp->game = game;
}

// Display destructor
void
GMd_free(GMdisplay *disp)
{
    if(disp == NULL) {
        return;
    }
    
    free(disp);

}

// get center of display
vec2i
GMd_center(GMdisplay *disp)
{
    if(disp == NULL) {
        return (vec2i){0, 0};
    }
    vec2i center = (vec2i){disp->cols / 2, disp->rows / 2};
    return center;
}

void
init_buffer(GMdisplay *disp)
{
    if(disp == NULL) {
        return;
    }

    // draw borders
    // newlines
    for(size_t i = 0; i < disp->rows; i++) 
    {
        for(int j = 0; j < disp->cols; j++) 
        {
            if((j == 0 || j == disp->cols-1) && (i == 0 || i == disp->cols-1))
            {
                disp->GMdbuffer[i][j] = border_pixel('c');
            }
            else if(i == 0 || i == disp->cols-1) 
            {
                disp->GMdbuffer[i][j] = border_pixel('h');
            } 
            else if(j == 0 || j == disp->cols-1)
            {
                disp->GMdbuffer[i][j] = border_pixel('v');
            }
            else 
            {
                disp->GMdbuffer[i][j] = blank_pixel();
            }

        }
        
    }


}

// draw game into buffer
void
buffer_game(GMdisplay *disp)
{
    if(disp == NULL || disp->game == NULL) {
        return;
    }

    Game *game = disp->game;

    // redraw area other than borders
    for(int i = 1; i < disp->rows-1; i++) 
    {
        for(int j = 1; j < disp->cols-1; j++) 
        {
            disp->GMdbuffer[i][j] = blank_pixel();
        }
    }

    // draw food
    disp->GMdbuffer[game->food.y][game->food.x] = food_pixel();

    
    // draw snake
    Snake *snake = game->player;
    for(int i = 0; i < snake->length; i++) 
    {
        vec2i pos = snake->body[i];
        // if(pos.x == game->food.x && pos.y == game->food.y)
        // {
        //     snake_grow(game->player);
        //     game->food = food_gen(game);

        // }
        food_check(game, 0);
        disp->GMdbuffer[pos.y][pos.x] = snake_pixel();
    }
}

// draw game
void
draw_game(GMdisplay *disp)
{
    if(disp == NULL) {
        return;
    }
    int i = 0;
    for(; i < disp->rows; i++) 
    {
        for(int j = 0; j < disp->cols; j++) 
        {
            TPixel pixel = disp->GMdbuffer[i][j];
            set_term_color(pixel.fg, pixel.bg, (vec2i*)NULL);
            putchar(pixel.c);
        }
        if(i != disp->rows-1)
            putchar('\n');
    }
    set_term_color(WHITE, BLACK, (vec2i*)NULL);
    CPOS(0, 0);
}