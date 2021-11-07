//
// Created by BrandonZu on 10/22/21.
//

#include "common.h"

// Runtime 7ms(>97%) | Memory Usage 10.6MB(>76%)
class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        if(n == m) {
            for(int i = 0; i < n; i++) {
                for(int j = i + 1; j < m; j++) {
                    swap(matrix[i][j], matrix[j][i]);
                }
            }
            return matrix;
        }
        else {
            vector<vector<int>> res(m, vector<int>(n));
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < m; j++) {
                    res[j][i] = matrix[i][j];
                }
            }
            return res;
        }
    }
};
