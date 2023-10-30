#ifndef SNK_TYPES_H
#define SNK_TYPES_H 1


/**
 * @brief Input keys for the game.
 * @enum INPUT_KEY 
 * @typedef INPUT_KEY
*/
typedef enum INPUT_KEY
{
    NONE    = -1,
    UP      = 'k',
    DOWN    = 'j',
    RIGHT   = 'l',
    LEFT    = 'h',
    SELECT  = '\n',
    START   = 's',
    QUIT    = 'q',
    PAUSE   = 'p',
    RESTART = 'r'
} // enum INPUT_KEY
INPUT_KEY; 

/**
 * @brief Game states
 * @enum STATE
 * @typedef STATE
*/
typedef
enum STATE
{
    MENU,
    PLAYING,
    PAUSED,
    GAME_OVER,
    GAME_QUIT
} // enum GAME_STATE
STATE; 

/**
 * @brief Tile types for map
 * @enum TILE
 * @typedef TILE
*/
typedef
enum TILE
{
    EMPTY   = 0,
    SNAKE   = 1,
    FOOD    = 2,
    VBORDER = 5,
    HBORDER = 6
} // enum TILE_TYPE
TILE;

/**
 * @brief Color codes for terminal
 * @enum COLOR
 * @typedef COLOR
*/
typedef
enum COLOR
{
    BLACK   = 30,
    RED     = 31,
    GREEN   = 32,
    YELLOW  = 33,
    BLUE    = 34,
    MAGENTA = 35,
    CYAN    = 36,
    WHITE   = 37
} // enum COLOR
COLOR;


#endif // !SNK_TYPES_H