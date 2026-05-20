#include <stdio.h>

#ifdef DEBUG
    #define WAYPOINT(msg) do { \
        printf("[DEBUG] Waypoint reached : %s at %s : %d\n", msg, __FILE__, __LINE__); \
    } while(0)
#else
    #define WAYPOINT(msg) //Do nothing in release build
#endif


int main()
{
    int x = 5;
    WAYPOINT("Before calculation");

    x+= 10;
    WAYPOINT("After calculation");

    return 0;
}