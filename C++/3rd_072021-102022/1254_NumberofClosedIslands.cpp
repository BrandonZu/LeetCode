//
// Created by BrandonZu on 11/7/21.
//

#include "common.h"

// Runtime 8ms(>98%) | Memory Usage 13.7MB(>15%)
class Solution {
    int count;
    const int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
public:
    bool bfs(vector<vector<int>>& grid, int start_x, int start_y) {
        int n = grid.size(), m = grid[0].size();
        queue<pair<int, int>> q;
        bool flag = true;

        q.push({start_x, start_y});
        grid[start_x][start_y] = 2;
        while(!q.empty()) {
            auto p = q.front();
            q.pop();
            for(int i = 0; i < 4; i++) {
                int new_x = p.first + dx[i], new_y = p.second + dy[i];
                if(new_x < 0 || new_x >= n || new_y < 0 || new_y >= m) {
                    flag = false;
                    continue;
                }
                if(grid[new_x][new_y] == 0) {
                    grid[new_x][new_y] = 2;
                    q.push({new_x, new_y});
                }
            }
        }
        return flag;
    }

    int closedIsland(vector<vector<int>>& grid) {
        count = 0;
        int n = grid.size(), m = grid[0].size();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 0) {
                    if(bfs(grid, i, j))
                        count++;
                }
            }
        }
        return count;
    }
};

