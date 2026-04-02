#include <stdio.h>
/*
On almost every modern system, this code will print:

    -1 is less than (unsigned char) 1 : ANSI C Semantics

Why does this happen? (The Mechanics)

To understand this, we have to look at the Usual Arithmetic Conversions and Integer Promotion rules in C.
 When you compare two different types, C tries to bring them to a "common type" before performing the comparison.
1. Integer Promotion

In the expression -1 < (unsigned char)1:

    -1 is an int.

    (unsigned char)1 is an unsigned char.

However, in C, any integer type smaller than an int (like char or short) is promoted to an int before an operation, provided an int can hold all the values of the original type. 
Since a standard int can easily hold the value 1 from an unsigned char, the unsigned char is promoted to a signed int.
2. The Comparison

Now the expression effectively becomes:
(int)-1 < (int)1

Since both operands are now signed integers, the comparison is straightforward: -1 is indeed less than 1. 
This is the "Value Preserving" approach adopted by ANSI C.

*/
int main(void)
{

    if(-1 < (unsigned char)1)
    {
        printf("-1 is less than (unsigned char) 1 : ANSI C Semantics \n");
    }
    else
    {
        printf("-1 is not less than (unsigned char) 1 : K & R Semantics \n");
    }

    return 0;
}

/*
K & R Semantics -> Promoted types became unsigned if the original was unsigned.
ANSI C Semantics -> Promoted types become int if int can hold the value.
*/