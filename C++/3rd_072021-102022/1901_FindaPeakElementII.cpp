//
// Created by BrandonZu on 10/30/21.
//

#include "common.h"

// Runtime 168ms(>65%) | Memory Usage 46MB(>62%)
class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        int l = 0, r = n - 1;
        while(l <= r) {
            int mid = l + r >> 1;
            int max_index = 0;
            for(int j = 1; j < m; j++) {
                if(mat[mid][j] > mat[mid][max_index])
                    max_index = j;
            }

            if(mid - 1 >= 0 && mat[mid - 1][max_index] > mat[mid][max_index]) {
                r = mid - 1;
            }
            else if(mid + 1 < n && mat[mid + 1][max_index] > mat[mid][max_index]) {
                l = mid + 1;
            }
            else {
                return {mid, max_index};
            }
        }
        return {-1, -1};
    }

};

