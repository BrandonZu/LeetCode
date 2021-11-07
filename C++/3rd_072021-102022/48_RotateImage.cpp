//
// Created by BrandonZu on 2021/8/18.
//

#include "common.h"

// Runtime 0ms(>100%) | Memory Usage 7.2MB(>32%)
class Solution1 {
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

// Runtime 0ms(>100%) | Memory Usage 7.2MB(>33%)
class Solution1_R1 {
public:
    void rotate(vector<vector<int>>& matrix) {
        for(int i = 0; i < matrix.size(); i++) {
            for(int j = i + 1; j < matrix[0].size(); j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        for(auto& line: matrix) {
            reverse(line.begin(), line.end());
        }
    }
};

// Runtime 0ms(>100%) | Memory Usage 7.2MB(>33%)
class Solution2 {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i = 0; i < n / 2; i++) {
            int len = n - 2 * i - 1, end = n - 1 - i;
            for(int j = 0; j < len; j++) {
                int tmp = matrix[i][i + j];
                matrix[i][i + j] = matrix[end - j][i];
                matrix[end - j][i] = matrix[end][end - j];
                matrix[end][end - j] = matrix[i + j][end];
                matrix[i + j][end] = tmp;
            }
        }
    }
};

