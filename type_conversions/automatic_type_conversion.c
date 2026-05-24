#include <stdio.h>

int main()
{
    if(sizeof(int) > -1)
        printf("True\n");
    else
        printf("False\n");
}

/*
output:
False

Automatic binary conversion:

-1 as an unsigned value is 0xFFFFFFFF

if one operand is unsigned int , then the other will be converted to unsigned int 
and result will be unsigned int

When evaluating expressions with different types, C promotes the "lower" type to the "higher" type based on this general ranking:

long double > double > float > unsigned long long > long long > unsigned long > long > unsigned int > int

*/