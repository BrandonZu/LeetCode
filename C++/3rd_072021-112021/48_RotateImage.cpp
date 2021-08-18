//
// Created by BrandonZu on 2021/8/18.
//

#include "common.h"

// Runtime 0ms(>100%) | Memory Usage 7.2MB(>32%)
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // Flip the matrix over its diagonal | Transpose the matrix
        // [i][j] -> [j][i]
        for(int i = 0; i < matrix.size(); i++) {
            for(int j = i + 1; j < matrix[i].size(); j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        // Reverse each row
        // [j][i] -> [j][N - i - 1]
        for(vector<int>& row: matrix) reverse(row.begin(), row.end());
    }
};
