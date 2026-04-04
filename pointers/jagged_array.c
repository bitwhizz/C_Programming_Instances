#include <stdio.h>

/*
A jagged array is a two-dimwnsional array possessing a different number of columns for each row.

*/

int main()
{
    /*
    we create the arr2 by declaring it as an array of pointers to an integer and using a block statement
    of compound literals to inititalize it.
    
    we used three compound literals to declare the jagged array.
    The array's element are initialized in row-column order starting with a value of zero;
    */
    int (*(arr2[])) = {
        (int[]){0,1,2,3},
        (int[]){4,5},
        (int[]){6,7,8}
    };

    //The next sequence required three for loops because each row had a different number of columns.
    int row = 0;
    for(int i=0; i<4 ; i++){
        printf("layer1[%d][%d] Address : %p value : %d\n",row,i,&arr2[row][i],arr2[row][i]);
    }
    printf("\n");

    row = 1;
    for(int i=0; i<2 ; i++){
        printf("layer1[%d][%d] Address : %p value : %d\n",row,i,&arr2[row][i],arr2[row][i]);
    }
    printf("\n");

    row = 2;
    for(int i=0; i<3 ; i++){
        printf("layer1[%d][%d] Address : %p value : %d\n",row,i,&arr2[row][i],arr2[row][i]);
    }
    printf("\n");

    return 0;
}