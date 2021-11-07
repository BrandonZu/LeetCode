//
// Created by BrandonZu on 9/24/21.
//

#include "common.h"

// Runtime 32ms(>40%) | Memory Cost 18MB(>7%)
class Solution_BFS {
public:
    int numIslands(vector<vector<char>>& grid) {
        int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
        int num = 0;
        int n = grid.size(), m = grid[0].size();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == '0')
                    continue;
                num++;
                queue<pair<int, int>> q;
                // Notice: Mark the position as visited before add it to the queue
                grid[i][j] = '0';
                q.push({i, j});
                while(!q.empty()) {
                    auto cur = q.front();
                    q.pop();
                    for(int i = 0; i < 4; i++) {
                        int xx = cur.first + dx[i], yy = cur.second + dy[i];
                        if(xx >= 0 && xx < n && yy >= 0 && yy < m && grid[xx][yy] == '1') {
                            grid[xx][yy] = '0';
                            q.push({xx, yy});
                        }
                    }
                }
            }
        }
        return num;
    }
};
