//
// Created by BrandonZu on 11/16/21.
//

#include "common.h"

// Runtime 12ms(>93%) | Memory Usage 10.4MB(>45%)
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int i = n - 1, j = 0;
        int res = 0;
        while(i >= 0 && j < m) {
            while(j < m && grid[i][j] >= 0)
                j++;
            res += m - j;
            i--;
        }
        return res;
    }
};

// Runtime 16ms(>67%) | Memory Usage 10.4MB(>45%)
class Solution_2 {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        if(grid[n - 1][m - 1] >= 0) return 0; // Binary Search requires valid number
        int t = 0, b = n - 1;
        while(t < b) {
            int mid = t + b >> 1;
            if(grid[mid][m - 1] < 0) {
                b = mid;
            }
            else {
                t = mid + 1;
            }
        }
        int res = 0;
        for(int i = t; i < n; i ++) {
            int l = 0, r = m - 1;
            while(l < r) {
                int mid = l + r >> 1;
                if(grid[i][mid] < 0) {
                    r = mid;
                }
                else {
                    l = mid + 1;
                }
            }
            res += m - l;
        }
        return res;
    }
};
