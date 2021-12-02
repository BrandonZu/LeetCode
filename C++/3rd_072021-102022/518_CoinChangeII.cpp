//
// Created by BrandonZu on 11/30/21.
//

#include "common.h"

// Runtime 8ms(>91%) | Memory Usage 7.1MB(>88%)
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<int> dp(amount + 1, 0);
        dp[0] = 1;
        for(int coin: coins) {
            for(int j = coin; j <= amount; j++) {
                dp[j] += dp[j - coin];
            }
        }
        return dp[amount];
    }
};
