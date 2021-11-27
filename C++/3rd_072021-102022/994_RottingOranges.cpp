//
// Created by BrandonZu on 11/27/21.
//

#include "common.h"

// Runtime 10ms(>23%) | Memory Usage 13MB(>49%)
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        const int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
        int n = grid.size(), m = grid[0].size();
        queue<pair<int, int>> q;
        int fresh_cnt = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 2)
                    q.push({i, j});
                else if(grid[i][j] == 1)
                    fresh_cnt++;
            }
        }
        int time = 0;
        while(!q.empty() && fresh_cnt) {
            time++;
            int sz = q.size();
            for(int i = 0; i < sz; i++) {
                auto p = q.front();
                q.pop();
                for(int d = 0; d < 4; d++) {
                    int x = p.first + dx[d], y = p.second + dy[d];
                    if(x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == 1) {
                        fresh_cnt--;
                        grid[x][y] = 2;
                        q.push({x, y});
                    }
                }
            }
        }
        return fresh_cnt == 0 ? time : -1;
    }
};
