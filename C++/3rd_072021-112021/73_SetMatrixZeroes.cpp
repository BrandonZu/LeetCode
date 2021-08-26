//
// Created by BrandonZu on 2021/8/26.
//

#include "common.h"

// Runtime 28ms(>10%) | Memory Usage 13MB(>96%)
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        bool row_0 = false, col_0 = false;
        for(int j = 0; j < m; j++)
            if(matrix[0][j] == 0)
                row_0 = true;
        for(int i = 0; i < n; i++)
            if(matrix[i][0] == 0)
                col_0 = true;
        for(int i = 1; i < n; i++) {
            for(int j = 1; j < m; j++) {
                if(matrix[i][j] == 0) {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }

        for(int i = 1; i < n; i++) {
            for(int j = 1; j < m; j++) {
                if(matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
            }
        }
        if(row_0) {
            for(int j = 0; j < m; j++)
                matrix[0][j] = 0;
        }
        if(col_0) {
            for(int i = 0; i < n; i++)
                matrix[i][0] = 0;
        }
    }
};
