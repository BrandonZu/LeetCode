//
// Created by BrandonZu on 2021/8/8.
//

#include "common.h"

// Runtime 104ms(>60%) | Memory Usage 14.8MB(>88%)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty()) return false;
        int x = 0, y = matrix[0].size() - 1;
        while(x < matrix.size() && 0 <= y) {
            if(matrix[x][y] == target)
                return true;
            else if(matrix[x][y] > target)
                y--;
            else
                x++;
        }
        return false;
    }
};
