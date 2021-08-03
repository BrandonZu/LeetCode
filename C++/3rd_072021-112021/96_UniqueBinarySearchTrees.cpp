//
// Created by BrandonZu on 2021/8/3.
//
#include "common.h"

// Runtime 0ms(>100%) | Memory Usage 6MB(>32%)
class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = 1;
        for(int i = 2; i <= n; i++)
            for(int j = 0; j <= i - 1; j++)
                dp[i] += dp[j] * dp[i - j - 1];

        return dp[n];
    }
};
