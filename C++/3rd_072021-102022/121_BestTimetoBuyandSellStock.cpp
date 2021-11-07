//
// Created by BrandonZu on 2021/8/11.
//

#include "common.h"

// Runtime 104ms(>92%) | Memory Usage 93MB(>53%)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int cur_min = prices[0], profit = 0;
        for(int p: prices) {
            profit = max(profit, p - cur_min);
            cur_min = min(cur_min, p);
        }
        return profit;
    }
};

// Runtime 128ms(>23%) | Memory Usage 93MB(>53%)
class Solution_DP {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int stock_0 = 0, stock_1 = -prices[0];
        for(int i = 1; i < n; i++) {
            stock_0 = max(stock_0, stock_1 + prices[i]);
            stock_1 = max(stock_1, -prices[i]);
        }
        return stock_0;
    }
};

