//
// Created by BrandonZu on 12/7/21.
//

#include "common.h"

// Runtime 8ms(>98%) | Memory Usage 12MB(>45%)
class Solution {
public:
    int minTotalDistance(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<int> row, col;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1) {
                    row.push_back(i);
                }
            }
        }
        for(int j = 0; j < m; j++) {
            for(int i = 0; i < n; i++) {
                if(grid[i][j] == 1) {
                    col.push_back(j);
                }
            }
        }
        return getMin(row) + getMin(col);
    }

    int getMin(vector<int>& cnt) {
        int mid = cnt.size() / 2;
        int dist = 0;
        for(int i: cnt) {
            dist += abs(cnt[mid] - i);
        }
        return dist;
    }
};
