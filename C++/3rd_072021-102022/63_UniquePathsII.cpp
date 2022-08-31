//
// Created by BrandonZu on 2021/8/2.
//

#include "common.h"

// Runtime 0ms(>100%) | Memory Usage 7.6MB(>60%)
class Solution {
    /*
     * if(grid[i][j] == 1)
     *   dp[i][j] = 0;
     * else
     *   dp[i][j] = dp[i - 1][j] + dp[i][j - 1]
     */
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid.empty() || obstacleGrid[0][0] == 1) return 0;
        vector<int> dp(obstacleGrid[0].size());

        // Init
        dp[0] = 1;
        for(int i = 0; i < obstacleGrid.size(); i++) {
            // Judge
            if(obstacleGrid[i][0] == 1)
                dp[0] = 0;

            for(int j = 1; j < obstacleGrid[0].size(); j++) {
                if(obstacleGrid[i][j] == 1)
                    dp[j] = 0;
                else
                    dp[j] = dp[j] + dp[j - 1];
            }
        }
        return dp[obstacleGrid[0].size() - 1];
    }
};

// R .47 | M .66
class Solution2 {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        dp[0][0] = grid[0][0] ? 0 : 1;
        for(int i = 1; i < n; i++) dp[i][0] = grid[i][0] || !dp[i - 1][0] ? 0 : 1;
        for(int j = 1; j < m; j++) dp[0][j] = grid[0][j] || !dp[0][j - 1] ? 0 : 1;
        for(int i = 1; i < n; i++) {
            for(int j = 1; j < m; j++) {
                if(grid[i][j]) {
                    dp[i][j] = 0;
                }
                else {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }
            }
        }
        return dp[n - 1][m - 1];
    }
};