#ifndef SNK_GAME_H
#define SNK_GAME_H 1

#include "enums.h"
#include "snake.h"
#include "food.h"

#include <stdint.h>

typedef
struct Game 
{
    uint32_t score;

    INPUT_KEY input;    
    STATE state;

    Food food;
    Snake *player;
} // struct Game
Game;


/// @brief Creates a new game
/// @return A pointer to the new game
Game *new_game();

int food_check(Game *game, int regen);




#endif // GAME_H
