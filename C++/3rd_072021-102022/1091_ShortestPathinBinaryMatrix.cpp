//
// Created by BrandonZu on 11/27/21.
//

#include "common.h"

// Runtime 48ms(>95%) | Memory Usage 19MB(>95%)
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        const int dx[] = {0, 0, 1, 1, 1, -1, -1, -1}, dy[] = {-1, 1, -1, 0, 1, -1, 0, 1};
        int n = grid.size(), m = grid[0].size();
        queue<pair<int, int>> q;
        int cnt = 1;
        if(grid[0][0] == 0) {
            q.push({0, 0});
            grid[0][0] = 1;
        }
        while(!q.empty()) {
            cnt++;
            int sz = q.size();
            for(int i = 0; i < sz; i++) {
                auto p = q.front();
                q.pop();
                if(p.first == n - 1 && p.second == m - 1) return cnt - 1;
                for(int d = 0; d < 8; d++) {
                    int x = p.first + dx[d], y = p.second + dy[d];
                    if(x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == 0) {
                        q.push({x, y});
                        grid[x][y] = 1;
                    }
                }
            }
        }
        return -1;
    }
};
