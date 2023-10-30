#ifndef SNK_FOOD_H
#define SNK_FOOD_H 1

#include "vmath.h"

typedef vec2i Food;

/// @brief Generates a new food at a random position on the map not occupied by snake
Food food_gen();

#endif // SNK_FOOD_H
