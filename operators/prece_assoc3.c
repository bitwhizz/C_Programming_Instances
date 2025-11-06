#include<stdio.h>

main()
{
int a=10;
a= a++*a--;
printf("a=%d",a);
}


/*

If a initially equals 10:

    a++ might evaluate to 10 (the original value of a) and then a becomes 11.
    a-- might evaluate to 11 (the current value of a) and then a becomes 10.
    The multiplication 10 * 11 would result in 110.
    This 110 would then be assigned back to a.
*/