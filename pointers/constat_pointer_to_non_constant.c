#include <stdio.h>

int main(){
    int a = 10;
    int b = 20;

    //ptr is a constant pointer to a non-constant integer
    int *const ptr = &a;

    printf("Initial value of a : %d\n",*ptr); //output : 10

    //We can modify the value at the pointed-to address
    *ptr = 15;
    printf("Modified value of a : %d\n",*ptr);
    printf("Value of a directly : %d\n",a);

    //Error : cannot change the pointer to point to a different variable
    //ptr = &b;
    
    return 0;
}