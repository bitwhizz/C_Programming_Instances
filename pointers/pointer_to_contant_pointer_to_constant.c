#include <stdio.h>

int main() {
    const int value = 10;
    const int * const p1 = &value; // Constant pointer to a constant int
    const int * const *p2 = &p1; // pointer variable to a constant pointer to a constant int

    printf("Value: %d\n", **p2); //output : 10

    // ALL of the following would result in compilation errors:
    // **p2 = 20;   // Error: cannot change the underlying integer
    // *p2 = NULL;  // Error: cannot change the intermediate pointer

    return 0;
}