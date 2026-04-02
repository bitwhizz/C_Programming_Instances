#include<stdio.h>

#define PASTE(a,b)  a##b
#define MARKS(subject)  marks_##subject

int main(){

    int k2 = 14, k3=25;
    int marks_chem = 75,marks_math = 81;

    printf("%d %d \n",PASTE(k,2),PASTE(k,3));
    printf("%d %d \n",MARKS(chem),MARKS(math));

    return 0;
}