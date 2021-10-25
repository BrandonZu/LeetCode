//
// Created by BrandonZu on 10/24/21.
//

#include "common.h"

// Runtime 92ms(>22%) | Memory Usage 7.7MB(>55%)
class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        if(jobDifficulty.size() < d) return -1;
        int n = jobDifficulty.size();
        vector<vector<int>> dp(d + 1, vector<int>(n + 1, INT_MAX / 2));
        dp[0][0] = 0;
        for(int k = 1; k <= d; ++k) {
            for(int i = k; i <= n; ++i) {
                int md = 0;
                for(int j = i - 1; j >= k - 1; --j) {
                    md = max(md, jobDifficulty[j - 1 + 1]); // 1 based index
                    dp[k][i] = min(dp[k][i], dp[k - 1][j] + md);
                }
            }
        }
        return dp[d][n];
    }
};

