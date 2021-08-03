//
// Created by BrandonZu on 2021/8/3.
//

#include "common.h"

// DP Unboundec Knapsack Problem
// Transfer Equation
// dp[i][j] = min(dp[i-1][j], dp[i][j-v[i]]+1)
// Optimized
// dp[j] = min(dp[j], dp[j-v[i]]+1)

// Runtime 72ms(>63%) | Memory Usage 14.4MB(>61%)
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        for(int i = 1; i <= coins.size(); i++) {
            for(int j = coins[i - 1]; j <= amount; j++) {
                dp[j] = min(dp[j], dp[j - coins[i - 1]] + 1);
            }
        }
        return dp[amount] == amount + 1 ? -1 : dp[amount];
    }
};

