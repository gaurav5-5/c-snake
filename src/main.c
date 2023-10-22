#define EXTERN 
#include "globals.h"
#undef EXTERN
#include "types.h"
#include "input.h"

#include <pthread.h>    
#include <unistd.h>
#include <stdio.h>

int main()
{
    pthread_t input_thread;

    if(pthread_create(&input_thread, NULL, direction_thread, NULL))
    {
        fprintf(stderr, "Error creating input thread\n");
        return 1;
    }

    enum INPUT_KEY prev = CURRENT_DIRECTION;
    enum GAME_STATE p2 = CURRENT_STATE;
    while(CURRENT_STATE != GAME_QUIT)
    {
        if(prev != CURRENT_DIRECTION || p2 != CURRENT_STATE)
        {
            printf("%a %c\n", (enum GAME_STATE)CURRENT_STATE, (char)CURRENT_DIRECTION);
            prev = CURRENT_DIRECTION;
            p2 = CURRENT_STATE;
        }
    }

    pthread_join(input_thread, NULL);

    return 0;
}
