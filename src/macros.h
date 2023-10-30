#ifndef SNK_MACROS_H
#define SNK_MACROS_H 1

/// Macro to check if on windows
#define WIN_CHK defined(_WIN32) || defined(_WIN64) || defined(WIN32) || defined(WIN64)

/// Macro to position cursor
#define CPOS(x, y) printf("\e[%d;%dH", y, x)

/// Macro to clear screen
#define CLRSCR() printf("\e[2J\e[H")


#endif // !SNK_MACROS_H