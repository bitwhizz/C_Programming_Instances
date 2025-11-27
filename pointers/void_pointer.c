/*
A void pointer is a pointer that can be used to point to any data of any arbitrary type.
A void pointer can be dereferenced only after explicit casting.
*/

#include <stdio.h>

int main()
{
    int a = 5;
    void *b = &a;
    printf("%d\n", *((int*)b));
}