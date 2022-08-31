//
// Created by BrandonZu on 2021/8/2.
//

#include "common.h"

// Runtime 0ms(>100%) | Memory Udage 6MB(>63%)
class Solution_DP {
    // dp[i][j] = dp[i - 1][j] + dp[i][j - 1]
    // Using Scrolling Array
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

// R .45 | M .46
class Solution2 {
    vector<vector<int>> dp;
public:
    int uniquePaths(int m, int n) {
        dp.resize(m, vector<int>(n, 0));
        dp[0][0] = 1;
        for(int i = 1; i < m; i++) dp[i][0] = 1;
        for(int j = 1; j < n; j++) dp[0][j] = 1;
        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }
};