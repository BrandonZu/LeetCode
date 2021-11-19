//
// Created by BrandonZu on 11/18/21.
//

#include "common.h"

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<int> res;
        int i = 0, j = 0;
        while(!(i == n - 1 && j == m - 1)) {
            if(i == 0)
        }
        res.push_back(mat[n - 1][m - 1]);
        return res;
    }
};
