#include "game.h"
#include "enums.h"
#include "food.h"

#include <stdlib.h>

// Game constructor
Game*
new_game()
{
    Game *g = malloc(sizeof(Game));
    if(g == NULL) {
        perror("game_new");
        exit(EXIT_FAILURE);
    }

    g->score = 0;
    g->state = (STATE)MENU;
    g->input = (INPUT_KEY)NONE;
    g->food = food_gen();
    g->player = NULL;

    return g;
}

int
food_check(Game *game, int regen)
{
    if(game->player->body[0].x == game->food.x && game->player->body[0].y == game->food.y) {
        game->food = food_gen();
        if(!regen)
        {
            snake_grow(game->player);
            game->score++;
        }
        return 1;
    }
    if(regen) {
        game->food = food_gen();
        food_check(game, regen);
    }
    return 0;
}