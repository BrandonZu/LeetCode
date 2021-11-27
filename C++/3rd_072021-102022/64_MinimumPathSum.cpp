//
// Created by BrandonZu on 2021/8/26.
//

#include "common.h"

// Runtime 11ms(>33%) | Memory Usage 9.8MB(>70%)
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<int> dp(m, 0);
        int s = 0;
        for(int j = 0; j < m; j++) {
            s += grid[0][j];
            dp[j] = s;
        }
        for(int i = 1; i < n; i++) {
            dp[0] += grid[i][0];
            for(int j = 1; j < m; j++) {
                dp[j] = min(dp[j], dp[j - 1]) + grid[i][j];
            }
        }
        return dp[m - 1];
    }
};

// Runtime 13ms(>23%) | Memory Usage 9.7MB(>68%)
class Solution_R1 {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<int> dp(m);
        int sum = 0;
        for(int j = 0; j < m; j++) {
            sum += grid[0][j];
            dp[j] = sum;
        }

        for(int i = 1; i < n; i++) {
            dp[0] += grid[i][0];
            for(int j = 1; j < m; j++) {
                dp[j] = min(dp[j], dp[j - 1]) + grid[i][j];
            }
        }
        return dp[m - 1];
    }
};
