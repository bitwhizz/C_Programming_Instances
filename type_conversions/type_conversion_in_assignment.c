#include <stdio.h>

int main(void)
{
    char c1 ,c2;
    int i1 , i2;
    float f1,f2;
    c1 = 'H';
    i1 = 80.56; /* Demotion : float converted to int , only 80 assigned to i1*/
    f1=12.6;
    c2=i1;   /*Demotion : int converted to char */
    i2 = f1;  /*Demotion : float converted to int*/
    /*Now c2 has charecter with ASCII value 80.2 is assigned value i2*/
    printf("c2 = %c , i2 = %d \n",c2,i2);
    f2=i1;  /*Promotion : int converted to float*/
    i2=c1; /*Promotion : int converted to int*/
    /*Now i2 contains ASCII value of character 'H' which is 72*/
    printf("f2 = %.2f , i2 = %d \n",f2,i2);
}

/*
output :
c2 = P , i2 = 12 
f2 = 80.00 , i2 = 72

Key Rules for Implicit Conversion:

    Integer Promotion: Any operand of type char, short, or an enumeration type is automatically converted to int (or unsigned int) before any operation is performed.

    Arithmetic Conversion: If you mix types in an operation (e.g., adding an int and a float), the compiler converts the lower-ranked type to the higher-ranked type.

    The "Demotion" Risk: If you assign a higher type to a lower type, the compiler will still do it automatically, but you may lose data (e.g., assigning a float to an int chops off the decimal part).

When evaluating expressions with different types, C promotes the "lower" type to the "higher" type based on this general ranking:

long double > double > float > unsigned long long > long long > unsigned long > long > unsigned int > int
*/
