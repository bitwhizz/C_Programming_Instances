/*
121. Best Time to Buy and Sell Stock

Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.

Example 1:
Input: [7, 1, 5, 3, 6, 4]
Output: 5

max. difference = 6-1 = 5 (not 7-1 = 6, as selling price needs to be larger than buying price)



Example 2:
Input: [7, 6, 4, 3, 1]
Output: 0

In this case, no transaction is done, i.e. max profit = 0.
*/

#include <stdio.h>

int maxProfit(int* prices, int pricesSize) {
    int i, d, k = 0;
    
    if (pricesSize < 2) return 0;
    
    // O(n)
    int cost = prices[0];
    for (i = 1; i < pricesSize; i ++) {
        if (prices[i] > cost) {
            d = prices[i] - cost;
            k = d > k ? d : k;
        } else {
            cost = prices[i];
        }
    }
    
    return k;
}

int main() {
    // Example 1: Standard case (Buy at 1, Sell at 6, Profit = 5)
    int stockPrices1[] = {7, 1, 5, 3, 6, 4};
    int size1 = sizeof(stockPrices1) / sizeof(stockPrices1[0]);
    int result1 = maxProfit(stockPrices1, size1);
    
    // Example 2: Prices only go down (Profit = 0)
    int stockPrices2[] = {7, 6, 4, 3, 1};
    int size2 = sizeof(stockPrices2) / sizeof(stockPrices2[0]);
    int result2 = maxProfit(stockPrices2, size2);

    // Printing the results
    printf("Test Case 1 Profit: %d\n", result1); 
    printf("Test Case 2 Profit: %d\n", result2);

    return 0;
}

/*
Difficulty:Easy
Total Accepted:207.9K
Total Submissions:504.8K


Companies Amazon Microsoft Bloomberg Uber Facebook
Related Topics Array Dynamic Programming
Similar Questions 
                
                  
                    Maximum Subarray
                  
                    Best Time to Buy and Sell Stock II
                  
                    Best Time to Buy and Sell Stock III
                  
                    Best Time to Buy and Sell Stock IV
                  
                    Best Time to Buy and Sell Stock with Cooldown
*/
