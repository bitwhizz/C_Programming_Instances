/*
136. Single Number

Given an array of integers, every element appears twice except for one. Find that single one.

Example 1:

Input: nums = [2,2,1]

Output: 1

Example 2:

Input: nums = [4,1,2,1,2]

Output: 4

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
*/

int singleNumber(int* nums, int numsSize) {
    int i, k = 0;
    for (i = 0; i < numsSize; i ++) {
        k = k ^ nums[i];  // a ^ a equals to 0; 0 ^ a equals to a
    }
    return k;
}


/*
Difficulty:Easy
Total Accepted:231K
Total Submissions:424.5K


Companies Palantir Airbnb
Related Topics Hash Table Bit Manipulation
Similar Questions 
                
                  
                    Single Number II
                  
                    Single Number III
                  
                    Missing Number
                  
                    Find the Duplicate Number
                  
                    Find the Difference
*/
