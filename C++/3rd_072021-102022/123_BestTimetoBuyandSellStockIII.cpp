//
// Created by BrandonZu on 2021/8/11.
//

#include "common.h"

// Runtime 116ms(>92%) | Memory Usage 75.2MB(>78%)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int hold1 = -prices[0], empty2 = 0, hold2 = -prices[0], end = 0;
        for(int i = 1; i < prices.size(); i++) {
            end = max(end, hold2 + prices[i]);
            hold2 = max(hold2, empty2 - prices[i]);
            empty2 = max(empty2, hold1 + prices[i]);
            hold1 = max(hold1, -prices[i]);
        }
        return max(max(empty2, end), 0);
    }
};

// R .52 | M .87
class Solution2 {
public:
    int maxProfit(vector<int>& prices) {
        int dp20 = INT32_MIN / 2, dp01 = -prices[0];
        int dp10 = INT32_MIN / 2, dp11 = INT32_MIN / 2;
        for(int i = 1; i < prices.size(); i++) {
            dp20 = max(dp20, dp11 + prices[i]);
            dp11 = max(dp11, dp10 - prices[i]);
            dp10 = max(dp10, dp01 + prices[i]);
            dp01 = max(dp01, -prices[i]);
        }
        return max(0, max(dp10, dp20));
    }
};
