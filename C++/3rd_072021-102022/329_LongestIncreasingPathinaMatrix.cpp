//
// Created by BrandonZu on 12/7/21.
//

#include "common.h"

// Runtime 45ms(>58%) | Memory Usage 16MB(>74%)
class Solution {
public:
    int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
    int n, m;
    vector<vector<int>> dp;
    int dfs(vector<vector<int>>& matrix, int i, int j) {
        if(dp[i][j] != -1) return dp[i][j];
        int max_len = 0;
        for(int d = 0; d < 4; d++) {
            int x = i + dx[d], y = j + dy[d];
            if(x >= 0 && x < n && y >= 0 && y < m && matrix[x][y] > matrix[i][j]) {
                int cur_len = dfs(matrix, x, y);
                dp[x][y] = cur_len;
                max_len = max(max_len, cur_len);
            }
        }
        return max_len + 1;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        n = matrix.size(), m = matrix[0].size();
        dp.resize(n + 1, vector<int>(m + 1, -1));
        int max_len = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                max_len = max(max_len, dfs(matrix, i, j));
            }
        }
        return max_len;
    }
};
