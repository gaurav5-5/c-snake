#ifndef SNK_INPUT_H
#define SNK_INPUT_H 1

#include "globals.h"

/**
 * @brief Thread for getting input from the user and changing states and setting directions
*/
void * direction_thread(void *);

/**
 * @brief Function for setting terminal to raw mode
*/
void enable_raw_mode();

/**
 * @brief Function for resetting the teminal
*/
void disable_raw_mode();


#endif //!SNK_INPUT_H