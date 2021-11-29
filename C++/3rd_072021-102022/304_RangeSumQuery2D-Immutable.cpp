//
// Created by BrandonZu on 11/28/21.
//

#include "common.h"

// Runtime 380ms(>73%) | Memory Usage 148MB(>80%)
class NumMatrix {
    vector<vector<int>> pre_sum;
    int n, m;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        n = matrix.size(), m = matrix[0].size();
        pre_sum.resize(n + 1, vector<int>(m + 1, 0));
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                pre_sum[i][j] = pre_sum[i - 1][j] + pre_sum[i][j - 1] - pre_sum[i - 1][j - 1] + matrix[i - 1][j - 1];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        row2++, col2++;
        return pre_sum[row2][col2] - pre_sum[row2][col1] - pre_sum[row1][col2] + pre_sum[row1][col1];
    }
};
