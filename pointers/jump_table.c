
/*
 *  jump_table.c
 *
 *  Created on: 25-Oct-2025
 *      Author: saif
 * 

For more on jump table creation refer the link below. 
https://barrgroup.com/blog/how-create-jump-tables-function-pointer-arrays-c-and-c 

*/

#include <stdio.h>

void operation_add(int a,int b){
    printf("Addition : %d + %d = %d\n",a,b,a+b);
}

void operation_subtract(int a,int b)
{
    printf("subtraction : %d - %d = %d\n",a,b,a-b);
}

void operation_multiply(int a,int b)
{
    printf("Multiplication : %d * %d = %d\n",a,b,a*b);
}

void operation_divide(int a, int b)
{
    if( b!= 0){
        printf("Division : %d / %d = %d \n", a,b,a/b);
    }else{
        printf("Error : Division by Zero \n");
    }
}

int main()
{
    // Declare an array of function pointers
    // Each function points to a function that takes two ints and return void
    static void (*const dispatch[])(int,int)={
        operation_add,
        operation_subtract,
        operation_multiply,
        operation_divide
    };

    int jump_index;
    int num1,num2;

    int num_operations = sizeof(dispatch) / sizeof(dispatch[0]);

    printf("Enter two numbers : ");
    scanf("%d %d",&num1,&num2);

    //Dispatch Loop
    while(1){
        printf("\n Choose an operation : \n");
        printf("0 : Add\n");
        printf("1 : Subtract\n");
        printf("2 : Multiply\n");
        printf("3 : Divide \n");
        printf("4 : Exit \n");
        printf("Enter your choice : ");
        scanf("%d",&jump_index);

        if(jump_index ==4){
            printf("\nExiting...\n");
            break;  //Exit the Loop
        }

        if(jump_index >= 0 && jump_index < num_operations){
            /*Call the function specified by jump_index*/
            dispatch[jump_index](num1 , num2);
        }
        else{
            printf("\n Invalid jump_index. Please try again : \n");
        }
    }

    return 0;
}

/*
Enter two numbers : 12 4

 Choose an operation : 
0 : Add
1 : Subtract
2 : Multiply
3 : Divide 
4 : Exit 
Enter your choice : 0
Addition : 12 + 4 = 16

 Choose an operation : 
0 : Add
1 : Subtract
2 : Multiply
3 : Divide 
4 : Exit 
Enter your choice : 1
subtraction : 12 - 4 = 8

 Choose an operation : 
0 : Add
1 : Subtract
2 : Multiply
3 : Divide 
4 : Exit 
Enter your choice : 2
Multiplication : 12 * 4 = 48

 Choose an operation : 
0 : Add
1 : Subtract
2 : Multiply
3 : Divide 
4 : Exit 
Enter your choice : 3
Division : 12 / 4 = 3 

 Choose an operation : 
0 : Add
1 : Subtract
2 : Multiply
3 : Divide 
4 : Exit 
Enter your choice : 4

Exiting...

*/