//
// Created by BrandonZu on 2021/8/11.
//

#include "common.h"

// Runtime 4md(>93%) | Memory Usage 10.8MB(>77%)
class Solution {
public:
    struct state {
        int hold, empty;
        state(int h, int e): hold(h), empty(e) {}
    };

    int maxProfit(int k, vector<int>& prices) {
        // dp[k].empty表示 至多 买卖k次时的最大收益
        vector<state> dp(k + 1, state(-1e9, 0));

        // Transfer
        for(int price : prices) {
            for(int j = k; j >= 1; j--) {
                dp[j].empty = max(dp[j].empty, dp[j].hold + price);
                dp[j].hold = max(dp[j].hold, dp[j - 1].empty - price);
            }
        }

        return dp[k].empty;
    }
};
