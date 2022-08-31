//
// Created by BrandonZu on 2021/8/2.
//
#include "common.h"

// dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2])

// Runtime 0ms(>100%) | Memory Usage 13.6MB(>64%)
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        if(cost.size() <= 2) return 0;
        int dp[2] = {0, 0};
        for(int i = 2; i <= cost.size(); i++) {
            int tmp = min(dp[1] + cost[i - 1], dp[0] + cost[i - 2]);
            dp[0] = dp[1];
            dp[1] = tmp;
        }
        return dp[1];
    }
};

// R .82 | M .96
class Solution2 {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int dp[2] = {0, 0};
        for(int i = 2; i < n + 1; i++) {
            int cur = min(dp[0] + cost[i - 2], dp[1] + cost[i - 1]);
            dp[0] = dp[1];
            dp[1] = cur;
        }
        return dp[1];
    }
};
