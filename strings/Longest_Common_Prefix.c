/*
14. Longest Common Prefix

Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

Example 1:

Input: ["flower","flow","flight"]
Output: "fl"


Example 2:

Input: ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.


Constraints:

1 <= strs.length <= 200
0 <= strs[i].length <= 200
strs[i] consists of only lowercase English letters if it is non-empty.

Note:

All given inputs are in lowercase letters a-z.
*/
#include <stdio.h>
#include <stdlib.h>

char* longestCommonPrefix(char** strs, int strsSize) {
    if (strsSize == 0) return "";
    if (strsSize == 1) return strs[0];

    int i, n = 0;
    char c;

    // Iterate through each character of the first string
    while (strs[0][n] != '\0') {
        c = strs[0][n]; // Set the character to compare against
        
        for (i = 1; i < strsSize; i++) {
            // If we hit the end of another string or find a mismatch
            if (strs[i][n] == '\0' || strs[i][n] != c) {
                strs[0][n] = '\0'; // Terminate the first string at the prefix
                return strs[0];
            }
        }
        n++;
    }

    strs[0][n] = '\0'; // Handle case where the entire first string is the prefix
    return strs[0];
}

int main() {
    // Array of strings to test
    // Note: We use character arrays (char[]) rather than string literals 
    // because the function modifies strs[0] in-place.
    char s1[] = "flower";
    char s2[] = "flow";
    char s3[] = "flight";
    
    char* test_strs[] = {s1, s2, s3};
    int size = 3;

    printf("Input: [\"flower\", \"flow\", \"flight\"]\n");
    char* result = longestCommonPrefix(test_strs, size);
    printf("Longest Common Prefix: %s\n", result);

    return 0;
}
/*
Difficulty:Easy


*/
