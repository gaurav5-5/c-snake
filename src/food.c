#include "food.h"

#include <stdlib.h>

Food
food_gen()
{
    Food food;
    food.x = rand() % 25 + 2;
    food.y = rand() % 25 + 2;

    return food;
}