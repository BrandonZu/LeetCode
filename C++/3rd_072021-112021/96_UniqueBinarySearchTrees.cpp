//
// Created by BrandonZu on 2021/8/3.
//
#include "common.h"

// Runtime 0ms(>100%) | Memory Usage 6MB(>64%)
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

// 1st Review 10/1/2021
// Runtime 0ms(>100%) | Memory Usage 6MB(>64%)
class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = 1;
        for(int len = 2; len <= n; len++) {
            for(int s = 1; s <= len; s++) {
                dp[len] += dp[s - 1] * dp[len - s];
            }
        }
        return dp[n];
    }
};