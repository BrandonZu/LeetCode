//
// Created by BrandonZu on 11/8/21.
//

#include "common.h"

// Runtime 8ms(>98%) | Memory Usage 17MB(>65%)
class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        for(int j = 0; j < m; j++) {
            int root = matrix[0][j];
            for(int i = 1; i < n && i + j < m; i++) {
                if(matrix[i][i + j] != root) {
                    return false;
                }
            }
        }

        for(int i = 1; i < n; i++) {
            int root = matrix[i][0];
            for(int j = 1; j < m && i + j < n; j++) {
                if(matrix[i + j][j] != root) {
                    return false;
                }
            }
        }
        return true;
    }
};
