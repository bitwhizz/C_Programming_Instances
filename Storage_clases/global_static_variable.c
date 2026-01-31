/*
When applieds static to global variables or functions.
it restricts their visibility to the file where they are declared ,
implementing the concept  of encapsulation at the file level.

*/

#include<stdio.h>

static int file_variable = 10;      //only c=visible in this file

void display(){
    printf("Static file variable : %d\n",file_variable);
}

int main(){
    display();
    file_variable = 20;
    display();
    return 0;
}