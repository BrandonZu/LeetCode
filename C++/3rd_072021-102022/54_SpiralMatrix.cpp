//
// Created by BrandonZu on 2021/7/23.
//

#include "common.h"

// Runtime 0ms(>100%) | Memory Usage 6.8MB(>90%)
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        int b = 0, t = matrix.size() - 1;
        if(t < 0) return result;
        int l = 0, r = matrix[0].size() - 1;
        while(l <= r && b <= t) {
            for(int i = l; i <= r; i++)
                result.push_back(matrix[b][i]);
            b++;
            if(b > t) break;
            for(int i = b; i <= t; i++)
                result.push_back(matrix[i][r]);
            r--;
            if(r < l) break;
            for(int i = r; i >= l; i--)
                result.push_back(matrix[t][i]);
            t--;
            if(t < b) break;
            for(int i = t; i >= b; i--)
                result.push_back(matrix[i][l]);
            l++;
            if(l > r) break;
        }
        return result;
    }
};

// 1st Review
// Runtime 0ms(>100%) | Memory Usage 6.8MB(>72%)
class Solution_R1 {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<int> res;
        int l = 0, r = m - 1, t = 0, b = n - 1;
        while(l <= r && t <= b) {
            for(int j = l; j <= r; j++) {
                res.push_back(matrix[t][j]);
            }
            t++;
            if(t > b) break;
            for(int i = t; i <= b; i++) {
                res.push_back(matrix[i][r]);
            }
            r--;
            if(r < l) break;
            for(int j = r; j >= l; j--) {
                res.push_back(matrix[b][j]);
            }
            b--;
            if(b < t) break;
            for(int i = b; i >= t; i--) {
                res.push_back(matrix[i][l]);
            }
            l++;
            if(l > r) break;
        }
        return res;
    }
};
