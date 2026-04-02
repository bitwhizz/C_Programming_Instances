#include <stdio.h>

/*
One of the most common uses for the stringizing operator is 
printing variable names alongside their values, which is great for debugging.
*/

#define PRINT_INT(var) printf("%s = %d\n", #var, var)

int main() {
    int current_score = 95;
    int high_score = 100;

    PRINT_INT(current_score);
    PRINT_INT(high_score);

    return 0;
}


/*

output:
current_score = 95
high_score = 100
*/