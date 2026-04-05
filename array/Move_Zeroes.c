/*
283. Move Zeroes

Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

For example, given nums  = [0, 1, 0, 3, 12], after calling your function, nums should be [1, 3, 12, 0, 0].

Note:
You must do this in-place without making a copy of the array.
Minimize the total number of operations.

Credits:Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.

This approach is an efficient Two-Pointer technique: 
    the first pointer (j) scouts for non-zero elements, and 
    the second pointer (i) writes them to the front of the array.
*/

#include <stdio.h>
#include <string.h> // Required for memset

/**
 * Moves all 0s to the end of the array while maintaining 
 * the relative order of non-zero elements.
 */
void moveZeroes(int* nums, int numsSize) {
    int i, j;
    
    // Pointer 'i' tracks the position for the next non-zero element
    // Pointer 'j' iterates through the entire array
    for (i = 0, j = 0; j < numsSize; j++) {
        if (nums[j] != 0) {
            nums[i++] = nums[j];
        }
    }
    
    // Fill the remaining positions from index 'i' to the end with zeroes
    // (j - i) calculates how many zeroes need to be appended
    memset(&nums[i], 0, (j - i) * sizeof(int));
}

// Helper function to print the array
void printArray(int* nums, int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("%d%s", nums[i], (i == size - 1) ? "" : ", ");
    }
    printf("]\n");
}

int main() {
    // Test Case 1: Standard mix of zeroes and non-zeroes
    int nums1[] = {0, 1, 0, 3, 12};
    int size1 = sizeof(nums1) / sizeof(nums1[0]);
    
    printf("Original 1: ");
    printArray(nums1, size1);
    
    moveZeroes(nums1, size1);
    
    printf("Modified 1: ");
    printArray(nums1, size1);

    printf("\n");

    // Test Case 2: Array with a single zero
    int nums2[] = {0};
    int size2 = 1;
    
    printf("Original 2: ");
    printArray(nums2, size2);
    
    moveZeroes(nums2, size2);
    
    printf("Modified 2: ");
    printArray(nums2, size2);

    return 0;
}