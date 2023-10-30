#include "macros.h"
#include "terminal.h"
#include "input.h"
#include "game.h"
#include "enums.h"
#include "display.h"
#include "vmath.h"
#include "snake.h"
#include "food.h"

#include <pthread.h>    
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


int main()
{
    GMdisplay *disp = GMd_new();
    Game *game = new_game();

    link_game(disp, game);
    game->player = new_snake(GMd_center(disp), 3, UP);

    pthread_t threads[2];

    if(pthread_create(&threads[0], NULL, input_thread, &game ))
    {
        fprintf(stderr, "Error creating input thread\n");
        return 1;
    }

    if(pthread_create(&threads[1], NULL, snake_thread, &game ))
    {
        fprintf(stderr, "Error creating snake thread\n");
        return 1;
    }

    init_buffer(disp);

    // sleep(1);
    CPOS(0, 0);

    while(game->state != GAME_QUIT)
    {
        buffer_game(disp);
        draw_game(disp);
        sleep(0.6);
        
        // CLRSCR();
    
    }

    pthread_join(threads[0], NULL);
    pthread_join(threads[1], NULL);

    set_term_color(WHITE, BLACK, NULL);

    return 0;
}
