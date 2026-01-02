/*
A void pointer is a pointer that can be used to point to any data of any arbitrary type.
A void pointer can be dereferenced only after explicit casting.
*/

#include <stdio.h>

int main()
{
    int a = 5;
    void *b = &a;
    void *pv = NULL;
    //printf("%d\n", sizeof(void*)); // output : 8
   //printf("%d\n", sizeof(pv); // output : 8
    //printf("%d\n", sizeof(*pv)); // output : 1
    printf("%d\n", *((int*)b));
}

/*
Pointer to void has two intresting properties:

1. A pointer to void has same representation and memory alignment as a pointer to char.

2. A pointer to void will never be equal to another pointer.However , two void pointers 
    assigned to NULL value will be equal.

*/