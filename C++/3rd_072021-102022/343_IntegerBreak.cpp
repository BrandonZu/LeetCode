//
// Created by BrandonZu on 2021/8/3.
//

#include "common.h"

// dp[i] = max(1 * dp[i - 1], 2 * dp[i - 2], 3 * dp[i - 3], ... (i - 1) * dp[1])
// dp[i]: The largest product of those integers broken from i

// Runtime 0ms(>100%) | Memory Usage 6.3MB(>6%)
class Solution_DP {
public:
    int integerBreak(int n) {
        vector<int> dp(n + 1);
        dp[1] = 1;
        for(int i = 2; i <= n; i++) {
            for(int j = 1; j <= i - 1; j++) {
                // Choose not to break number i -> j * (i - j)
                // Choose to break number i -> j * dp[i - j]
                dp[i] = max(dp[i], max(j * dp[i - j], j * (i - j)));
            }
        }
        return dp[n];
    }
};

// Runtime 0ms(>100%) | Memory Usage 5.9MB (>70.2%)
class Solution_Greedy {
public:
    int integerBreak(int n) {
        if(n <= 2) return 1;
        if(n == 3) return 2;
        if(n == 4) return 4;
        int res = 1;
        while(n > 4) {
            res *= 3;
            n -= 3;
        }
        return res * n;
    }
};