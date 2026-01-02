#include <stdio.h>

int main(){
    int a = 10;
    int b = 20;

    //ptr is a constant pointer to a constant integer
    const int *const ptr = &a;

    printf("value pointed to by ptr : %d\n",*ptr); //output : 10
    printf("Address stored in ptr : %p\n",(void*)ptr);

    /*
        *ptr = 30; //Error : cannot modify the value through ptr, as the data is const
        ptr = &b; //Error : cannot change the address in ptr , as the pointer is const
    */
    
    return 0;
}