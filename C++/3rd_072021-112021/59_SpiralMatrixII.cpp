//
// Created by BrandonZu on 2021/7/23.
//

#include "common.h"

// Runtime 0ms(>100%) | Memory Usage 6.6MB(>63%)
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int num = 1;
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        int l = 0, r = n - 1, b = 0, t = n - 1;
        while(l <= r && b <= t) {
            for(int j = l; j <= r; j++)
                matrix[b][j] = num++;
            if(++b > t) break;
            for(int i = b; i <= t; i++)
                matrix[i][r] = num++;
            if(--r < l) break;
            for(int j = r; j >= l; j--)
                matrix[t][j] = num++;
            if(--t < b) break;;
            for(int i = t; i >= b; i--)
                matrix[i][l] = num++;
            if(++l > r) break;
        }
        return matrix;
    }
};
