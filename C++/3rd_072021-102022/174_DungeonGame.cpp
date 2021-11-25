//
// Created by BrandonZu on 11/24/21.
//

#include "common.h"

// Runtime 15ms(>15%) | Memory Usage 9MB(>50%)
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n = dungeon.size(), m = dungeon[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 1e8));
        dp[n - 1][m - 1] = max(1, 1 - dungeon[n - 1][m - 1]);
        for(int i = n - 1; i >= 0; i--) {
            for(int j = m - 1; j >= 0; j--) {
                if(i == n - 1 && j == m - 1)
                    continue;
                else {
                    if(i + 1 < n)
                        dp[i][j] = min(dp[i][j], dp[i + 1][j]);
                    if(j + 1 < m)
                        dp[i][j] = min(dp[i][j], dp[i][j + 1]);
                    dp[i][j] = max(1, dp[i][j] - dungeon[i][j]);
                }
            }
        }
        return dp[0][0];
    }
};

