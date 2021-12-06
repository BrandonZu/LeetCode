//
// Created by BrandonZu on 12/5/21.
//

#include "common.h"

// Runtime 52ms(>85%) | Memory Usage 18.7MB(>78%)
class Solution {
public:
    int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};

    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        queue<pair<int, int>> q;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1)
                    q.push({i, j});
            }
        }
        if(q.empty() || q.size() == n * n)
            return -1;
        int step = 0;
        while(!q.empty()) {
            step++;
            int sz = q.size();
            for(int i = 0; i < sz; i++) {
                auto p = q.front();
                q.pop();
                for(int d = 0; d < 4; d++) {
                    int x = p.first + dx[d], y = p.second + dy[d];
                    if(x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == 0) {
                        q.push({x, y});
                        grid[x][y] = step;
                    }
                }
            }
        }
        return step - 1;
    }
};
