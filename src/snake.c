#include "snake.h"

#include "vmath.h"
#include "enums.h"
#include "game.h"

#include <pthread.h>

#include <unistd.h>
#include <stdlib.h>
#include <stdint.h>

// Snake constructor
Snake *new_snake(const vec2i pos, const int length, const INPUT_KEY direction)
{
    Snake *s = malloc(sizeof(Snake));
    if(s == NULL) {
        perror("snake_new");
        exit(EXIT_FAILURE);
    }

    s->length = length;
    s->direction = direction;
    s->body = malloc(sizeof(vec2i) * length);
    if(s->body == NULL) {
        perror("snake_new");
        exit(EXIT_FAILURE);
    }
    for(size_t i = 0; i < s->length; i++) {
        s->body[i].x = pos.x;
        s->body[i].y = pos.y + i;
    }
    
    return s;
}

// Snake destructor
void snake_free(Snake *snk)
{
    if(snk) {
        free(snk->body);
        free(snk);
    }
}

// Snake move
void snake_move(Snake *snk)
{
    for(int i = snk->length - 1; i > 0; i--) 
    {
        snk->body[i] = snk->body[i - 1];
    }
    switch(snk->direction) 
    {
        case UP:
            if(snk->body[0].y-- < 1)
                snk->body[0].y = 28;
            break;
        case DOWN:
            if(snk->body[0].y++ > 29)
                snk->body[0].y = 1;
            break;
        case LEFT:
            if(snk->body[0].x-- < 1)
                snk->body[0].x = 28;
            break;
        case RIGHT:
            if(snk->body[0].x++ > 29)
                snk->body[0].x = 1;
            break;
        default:
            break;
    }
}

// Snake grow
void snake_grow(Snake *snk)
{
    snk->length++;
    snk->body = realloc(snk->body, sizeof(vec2i) * snk->length);
    if(snk->body == NULL) {
        perror("snake_grow");
        exit(EXIT_FAILURE);
    }
    snk->body[snk->length-1] = snk->body[snk->length-2];
}

// Snake thread
void * snake_thread(void *arg)
{
    Game *game = *(Game**)arg;
    while(game->state != GAME_QUIT) 
    {
        Snake *snk = game->player;
        switch(game->state)
        {
            case PLAYING:
                snake_move(snk);
                break;

            case GAME_QUIT:
                continue;
            case GAME_OVER:
            case PAUSED:
            default:
                break;

        }
        sleep(1);
    }
    return NULL;
}