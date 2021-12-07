//
// Created by BrandonZu on 12/6/21.
//

#include "common.h"

// Runtime 24ms(>40%) | Memory Usage 26.8MB(>20%)
class Solution {
    int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
    int n, m;
public:
    int getIslandArea(vector<vector<int>>& grid, int i, int j) {
        int area = 1;
        queue<pair<int, int>> q;
        q.push({i, j});
        grid[i][j] = -1;
        while(!q.empty()) {
            auto p = q.front();
            q.pop();
            for(int d = 0; d < 4; d++) {
                int x = p.first + dx[d], y = p.second + dy[d];
                if(x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == 1) {
                    grid[x][y] = -1;
                    area++;
                    q.push({x, y});
                }
            }
        }
        return area;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        int max_area = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1) {
                    max_area = max(max_area, getIslandArea(grid, i, j));
                }
            }
        }
        return max_area;
    }
};
