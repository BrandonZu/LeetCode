//
// Created by BrandonZu on 12/6/21.
//

#include "common.h"

// Runtime 28ms(>100%) | Memory Usage 18.4MB(>88%)
class Solution {
public:
    int shortestBridge(vector<vector<int>>& grid) {
        const int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
        int n = grid.size(), m = grid[0].size();
        int i, j;
        for(int x = 0; x < n; x++) {
            for(int y = 0; y < m; y++) {
                if(grid[x][y] == 1) {
                    i = x, j = y;
                    break;
                }
            }
        }
        queue<pair<int, int>> paint, q;
        q.push({i, j}), paint.push({i, j});
        grid[i][j] = 2;
        while(!paint.empty()) {
            auto p = paint.front();
            paint.pop();
            for(int d = 0; d < 4; d++) {
                int x = p.first + dx[d], y = p.second + dy[d];
                if(x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == 1) {
                    grid[x][y] = 2;
                    q.push({x, y}), paint.push({x, y});
                }
            }
        }

        int step = 2;
        while(!q.empty()) {
            step++;
            int sz = q.size();
            for(int i = 0; i < sz; i++) {
                auto p = q.front();
                q.pop();
                for(int d = 0; d < 4; d++) {
                    int x = p.first + dx[d], y = p.second + dy[d];
                    if(x >= 0 && x < n && y >= 0 && y < m && grid[x][y] <= 1) {
                        if(grid[x][y] == 1)
                            return step - 3;
                        grid[x][y] = step;
                        q.push({x, y});
                    }
                }
            }
        }
        return step - 1;
    }
};
