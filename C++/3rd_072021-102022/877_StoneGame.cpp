//
// Created by BrandonZu on 10/3/21.
//

#include "common.h"

// Runtime 16ms(>31%) | Memory Usage 16.4MB(>17%)
class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for(int len = 1; len <= n; len++) {
            for(int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;
                if(len == 1)
                    dp[i][j] = piles[i];
                else
                    dp[i][j] = max(piles[i] - dp[i + 1][j], piles[j] - dp[i][j - 1]);
            }
        }
        return dp[0][n - 1] > 0;
    }
};
