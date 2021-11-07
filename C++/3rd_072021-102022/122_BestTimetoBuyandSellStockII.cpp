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
