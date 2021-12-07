//
// Created by BrandonZu on 12/6/21.
//

#include "common.h"

class Solution {
    int n, m;
    vector<vector<bool>> visited;
    int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
public:
    bool dfs(vector<vector<char>>& grid, int cur_i, int cur_j, int last_i, int last_j, char cur_char) {
        visited[cur_i][cur_j] = true;
        for(int d = 0; d < 4; d++) {
            int x = cur_i + dx[d], y = cur_j + dy[d];
            if(x >= 0 && x < n && y >= 0 && y < m && !(x == last_i && y == last_j) && grid[x][y] == cur_char) {
                if(visited[x][y] || dfs(grid, x, y, cur_i, cur_j, cur_char))
                    return true;
            }
        }
        return false;
    }

    bool containsCycle(vector<vector<char>>& grid) {
        n = grid.size(), m = grid[0].size();
        visited.resize(n, vector<bool>(m, false));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(!visited[i][j]) {
                    if(dfs(grid, i, j, -1, -1, grid[i][j]))
                        return true;
                }
            }
        }
        return false;
    }
};

