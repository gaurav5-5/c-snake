#ifndef SNK_SNAKE_H
#define SNK_SNAKE_H 1

#include "vmath.h"
#include "enums.h"

#include <pthread.h>
#include <stdint.h>

/// @brief Snake struct
typedef struct
{
    int length;
    INPUT_KEY direction;

    vec2i *body;
} Snake;

/// @brief Snake constructor
/// @param pos initial position
/// @param length initial length
/// @param direction initial direction
/// @return Snake instance
Snake *new_snake(vec2i pos, int length, INPUT_KEY direction);

/// @brief Snake destructor
/// @param snk Snake instance
void snake_free(Snake *snk);

/// @brief Snake move
/// @param snk Snake
void snake_move(Snake *snk);

/// @brief Snake grow
/// @param snk Snake
void snake_grow(Snake *snk);

/// @brief Snake thread
/// @param arg Snake instance
/// @return NULL
void * snake_thread(void *arg);

#endif // SNK_SNAKE_H
