//
// Created by BrandonZu on 2021/8/2.
//

#include "common.h"

// dp[i][j] = dp[i - 1][j] + dp[i][j - 1]
// Using Scrolling Array

// Runtime 0ms(>100%) | Memory Udage 6MB(>63%)
class Solution_DP {
public:
    int uniquePaths(int m, int n) {
        int x = max(m, n), y = min(m, n);
        vector<int> dp(y + 1, 0);
        dp[1] = 1;
        for(int i = 1; i <= x; i++) {
            for(int j = 2; j <= y; j++) {
                dp[j] = dp[j] + dp[j - 1];
            }
        }
        return dp[y];
    }
};