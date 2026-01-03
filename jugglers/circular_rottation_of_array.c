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
    for(int a=0;a<size;a++)   
    scanf("%d",&arr[a]);    
    int n;
    printf("Enter the index from where you want your array to rotate ");
    scanf("%d",&n);        
    printf("Array: \n");    
    for (int a = 0; a < size; a++) {     
        printf("%d ", arr[a]);     
    }             

    for(int a = 0; a < n; a++) {
        int b, temporary;
        temporary = arr[size-1]; 
        for(b = size-1; b > 0; b--)
        {    
            arr[b] = arr[b-1];    
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