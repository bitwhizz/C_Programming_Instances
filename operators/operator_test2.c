#include<stdio.h>
main()
{
int a=-3;
a=-a-a+!a;
printf("%d",a);
}

/*
 Negating a negative value results in a positive value. 
 Therefore, -(negative three) becomes positive three.
*/