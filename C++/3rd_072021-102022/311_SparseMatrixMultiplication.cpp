//
// Created by BrandonZu on 12/7/21.
//

#include "common.h"

// Runtime 4ms(>85%) | Memory Usage 8.3MB(>13%)
class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& mat1, vector<vector<int>>& mat2) {
        int n = mat1.size(), k = mat1[0].size(), m = mat2[0].size();
        vector<vector<int>> res(n, vector<int>(m, 0));
        vector<unordered_set<int>> row1(n), col2(m);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < k; j++) {
                if(mat1[i][j] != 0) {
                    row1[i].insert(j);
                }
            }
        }
        for(int j = 0; j < m; j++) {
            for(int i = 0; i < k; i++) {
                if(mat2[i][j] != 0) {
                    col2[j].insert(i);
                }
            }
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                for(int p: row1[i]) {
                    if(col2[j].find(p) != col2[j].end()) {
                        res[i][j] += mat1[i][p] * mat2[p][j];
                    }
                }
            }
        }
        return res;
    }
};
