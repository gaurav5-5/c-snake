#ifndef SNK_TYPES_H
#define SNK_TYPES_H 1

/**
 * @brief Input keys for the game.
 * @enum INPUT_KEY 
*/
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
}; // enum INPUT_KEY

/**
 * @brief Game states
 * @enum GAME_STATE
*/
enum GAME_STATE
{
    MENU,
    PLAYING,
    PAUSED,
    GAME_OVER,
    GAME_QUIT
}; // enum GAME_STATE

#endif // !SNK_TYPES_H