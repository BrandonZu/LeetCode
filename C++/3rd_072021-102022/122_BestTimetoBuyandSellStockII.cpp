//
// Created by BrandonZu on 2021/8/11.
//

#include "common.h"

// Runtime 4ms(>92%) | Memory Usage 13MB(>44%)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int dp_0 = 0, dp_1 = -prices[0];
        for(int i = 1; i < n; i++) {
            int pre_0 = dp_0;
            dp_0 = max(dp_0, dp_1 + prices[i]);
            dp_1 = max(dp_1, pre_0 - prices[i]);
        }
        return dp_0;
    }
};

// R .60 | M .59
class Solution2 {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int low = 0, high = 0;
        for(int i = 1; i < prices.size(); i++) {
            if(prices[i] > prices[i - 1]) {
                high = i;
            }
            else {
                profit += prices[high] - prices[low];
                low = high = i;
            }
        }
        if(low != high) {
            profit += prices[high] - prices[low];
        }
        return profit;
    }
};

// R .54 | M .60
class Solution3 {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> dp(2, 0);
        dp[0] = 0, dp[1] = -prices[0];
        for(int i = 1; i < n; i++) {
            int dp_0 = dp[0];
            dp[0] = max(dp[0], dp[1] + prices[i]);
            dp[1] = max(dp[1], dp_0 - prices[i]);
        }
        return dp[0];
    }
};
