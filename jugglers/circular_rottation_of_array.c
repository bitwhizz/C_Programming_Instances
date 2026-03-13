/*
Write a code to find circular rotation of an array by K positions.

This problem asks to find the circular rotation of an array by K positions.

    In a circular rotation, elements that are moved from the end of the array are appended to the beginning.
    Example for array [1, 2, 3, 4, 5] and K = 2:
    After rotating the array by 2 positions, the result will be [4, 5, 1, 2, 3].

*/


#include<stdio.h>        
int main()    
{             
    int size;
    printf("Size of array: ");
    scanf("%d",&size); 

    int arr[size];
    printf("Enter the elements ");
    for(int i=0;i<size;i++)   
        scanf("%d",&arr[i]); 

    int rindex;
    printf("Enter the index from where you want your array to rotate ");
    scanf("%d",&rindex);

    printf("Array: \n");    
    for (int i = 0; i < size; i++) {     
        printf("%d ", arr[i]);     
    }             

    for(int i = 0; i < rindex; i++) {
        int irotate, temporary;
        temporary = arr[size-1]; 
        for(irotate = size-1; irotate > 0; irotate--)
        {    
            arr[irotate] = arr[irotate-1];    
        }    
        arr[0] = temporary;    
    }            

    printf("\n");            
    printf("New Array: \n");    
    for(int a = 0; a< size; a++){    
        printf("%d ", arr[a]);    
    }    
    printf("\n");    

    return 0;    
}

/*

saif@saif-Inspiron-5547:~/programmer/C_Programming_Instances /jugglers$ ./circular_rottation_of_array 
Size of array: 10
Enter the elements 1 2 3 4 5 6 7 8 9 10
Enter the index from where you want your array to rotate 6
Array: 
1 2 3 4 5 6 7 8 9 10 
New Array: 
5 6 7 8 9 10 1 2 3 4 
*/