#ifndef SNK_DISPLAY_H
#define SNK_DISPLAY_H 1

#include "vmath.h"
#include "game.h"
#include "terminal.h"

#include <stdint.h>

/// @brief Display data structure
typedef
struct GMdisplay
{
    int rows;
    int cols;

    TPixel GMdbuffer[30][30];

    Game *game;
} // struct GMdisplay 
GMdisplay;

/// @brief Display constructor
/// @return Display instance
GMdisplay *GMd_new(void);

/// @brief Display destructor
/// @param disp Display instance
void GMd_free(GMdisplay *disp);

/// @brief get center of display
/// @param disp Display instance
/// @return center of display
vec2i GMd_center(GMdisplay *disp);

/// @brief links a game to a display
/// @param disp display
/// @param game game
void link_game(GMdisplay *disp, Game *game);

/// @brief initializes buffer with borders
/// @param disp display
void init_buffer(GMdisplay *disp);

/// @brief draws game into buffer
/// @param disp display
void buffer_game(GMdisplay *disp);

/// @brief draws buffer into terminal
/// @param disp display
void draw_game(GMdisplay *disp);




#endif // !SNK_DISPLAY_H