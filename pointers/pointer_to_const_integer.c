#include <stdio.h>

int main(){
    const int a = 10;
    const int b = 20;

    //ptr is a pointer variable to constant integer
    //The const applies to the integer, not the pointer.
    const int *ptr;

    ptr = &a; //Allowed the pointer itself can changed to point to 'a'
    printf("Value pointed to by ptr : %d\n",*ptr); //output : 10

    ptr = &b;   //Allowed the pointer itself can changed to point to different addres ('b')
    printf("Value pointed to by ptr : %d\n",*ptr); //output : 20

    return 0;
}