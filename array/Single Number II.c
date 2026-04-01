/*
137. Single Number II

Given an array of integers, every element appears three times except for one, which appears exactly once. Find that single one.

Example 1:

Input: nums = [2,2,3,2]
Output: 3
Example 2:

Input: nums = [0,1,0,1,0,1,99]
Output: 99

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
*/

int singleNumber(int* nums, int numsSize) {
    int i, ones, twos;
    ones = twos = 0;
    for (i = 0; i < numsSize; i ++) {
        ones = (ones ^ nums[i]) & ~twos;
        twos = (twos ^ nums[i]) & ~ones;
    }
    return ones;
}


/*
Difficulty:Medium
Total Accepted:119.8K
Total Submissions:288.6K


Related Topics Bit Manipulation
Similar Questions Single Number Single Number III

*/
