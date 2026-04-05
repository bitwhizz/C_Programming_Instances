/*
268. Missing Number

Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.


For example,
Given nums = [0, 1, 3] return 2.



Note:
Your algorithm should run in linear runtime complexity. Could you implement it using only constant extra space complexity?


Credits:Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.
*/
#include <stdio.h>

/**
 * Function to find the missing number in an array of size n 
 * containing numbers from 0 to n.
 */
int missingNumber(int* nums, int numsSize) {
    int i, k;
    
    // Using Gauss Summation Formula: Sum = n * (n + 1) / 2
    // This calculates the sum of all numbers from 0 to numsSize
    k = numsSize * (numsSize + 1) / 2;
    
    // Subtract each number present in the array from the expected sum
    for (i = 0; i < numsSize; i++) {
        k -= nums[i];
    }
    
    // The remaining value of k is the missing number
    return k;
}

int main() {
    // Test Case 1: n=3, numbers {0, 1, 3}. Missing: 2
    int nums1[] = {3, 0, 1};
    int size1 = 3;
    printf("Test 1 - Expected: 2, Result: %d\n", missingNumber(nums1, size1));

    // Test Case 2: n=9. Missing: 8
    int nums2[] = {9, 6, 4, 2, 3, 5, 7, 0, 1};
    int size2 = 9;
    printf("Test 2 - Expected: 8, Result: %d\n", missingNumber(nums2, size2));

    // Test Case 3: n=2, numbers {0, 1}. Missing: 2
    int nums3[] = {0, 1};
    int size3 = 2;
    printf("Test 3 - Expected: 2, Result: %d\n", missingNumber(nums3, size3));

    return 0;
}

