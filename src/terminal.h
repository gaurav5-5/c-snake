#ifndef SNK_TERMINAL_H
#define SNK_TERMINAL_H 1

#include "vmath.h"
#include "enums.h"

/// @brief terminal pixel
typedef
struct TPixel
{
    COLOR fg;
    COLOR bg;
    char c;
} 
TPixel;

/// @brief set/unset raw mode
void toggle_raw_mode(void);

/// @brief get terminal size
/// @return terminal size
vec2i get_term_size(void);

/// @brief set terminal color
/// @param fg foreground color
/// @param bg background color
/// @param cell cell
void set_term_color(COLOR fg, COLOR bg, vec2i *cell);

/// @brief  convert foreground color to background color
/// @param fg foreground color
/// @return background color
COLOR fg2bg(COLOR fg);

/// @brief get a border pixel
/// @param pos is corner?
/// @return border pixel
TPixel border_pixel(char pos);

/// @brief get a snake pixel
/// @return snake pixel
TPixel snake_pixel(void);

/// @brief get a food pixel
/// @return food pixel
TPixel food_pixel(void);

/// @brief blank pixel
/// @return blank pixel
TPixel blank_pixel(void);

#endif // SNK_TERMINAL_H

