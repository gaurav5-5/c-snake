#ifndef SNK_TYPES_H
#define SNK_TYPES_H 1

/**
 * @brief Input keys for the game.
 * @enum INPUT_KEY 
 * @typedef INPUT_KEY
*/
typedef
enum INPUT_KEY
{
    UP       = 119, /**< w */
    DOWN     = 120, /**< x */
    LEFT     =  97, /**< a */
    RIGHT    = 100, /**< d */

    START    = 115, /**< s */
    QUIT     = 113, /**< q */
    RESTART  = 114, /**< r */
    PAUSE    = 112, /**< p */

    NONE            /**< nothing*/
} // enum INPUT_KEY
INPUT_KEY; 

/**
 * @brief Game states
 * @enum GAME_STATE
 * @typedef GAME_STATE
*/
typedef
enum GAME_STATE
{
    MENU,
    PLAYING,
    PAUSED,
    GAME_OVER,
    GAME_QUIT
} // enum GAME_STATE
 GAME_STATE; 

/**
 * @brief Tile types for map
 * @enum TILE_TYPE
*/
typedef
enum TILE_TYPE
{
    EMPTY,
    SNAKE,
    FOOD
} // enum TILE_TYPE
TILE_TYPE; 

/**
 * Grid for main game
 * @struct Grid
 * @typedef grid
 * @var width  width of grid
 * @var height height of grid
*/
typedef 
struct Grid
{
    int width;
    int height;
    TILE_TYPE **tiles;
} // struct Grid
grid;


#endif // !SNK_TYPES_H