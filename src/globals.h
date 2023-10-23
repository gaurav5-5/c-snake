#ifndef SNK_GLOBALS_H
#define SNK_GLOBALS_H 1

#include "types.h"

/**
 * @brief Macro for externing variables
 * @var EXTERN sets external or internal linkage
 * @var INIT   sets value of variable
*/
#ifndef EXTERN 
#   define EXTERN extern
#   define INIT(...)
#else
#   define INIT(...) = __VA_ARGS__
#endif // !EXTERN

/**
 * @brief Current direction
 * @var CURRENT_DIRECTION stores the current direction
*/
EXTERN enum INPUT_KEY CURRENT_DIRECTION INIT(NONE);

/**
 * @brief Current game state
 * @var CURRENT_STATE stores the current game state
*/
EXTERN enum GAME_STATE CURRENT_STATE INIT(MENU);





#endif // !SNK_GLLOBALS_H