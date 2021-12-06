//
// Created by BrandonZu on 12/6/21.
//

#include "common.h"

// Runtime 72ms(>99%) | Memory Usage 96MB(>57%)
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        const int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
        int n = grid.size(), m = grid[0].size();
        int peri = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1) {
                    for(int d = 0; d < 4; d++) {
                        int x = i + dx[d], y = j + dy[d];
                        if(x < 0 || x >= n || y < 0 || y >= m)
                            peri++;
                        else if(grid[x][y] == 0)
                            peri++;
                    }
                }
            }
        }
        return peri;
    }
};
