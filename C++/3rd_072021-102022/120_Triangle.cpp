//
// Created by BrandonZu on 2021/8/7.
//

#include "common.h"
using namespace std;

// Runtime 4ms(>91%) | Memory Usage 8.4MB(>78%)
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<int> dp(205, 0);
        dp[0] = triangle[0][0];
        for(int i = 1; i < triangle.size(); i++) {
            for(int j = i; j >= 0; j--) {
                if(j == 0) {
                    dp[j] = dp[j] + triangle[i][j];
                }
                else if(j == i) {
                    dp[j] = dp[j - 1] + triangle[i][j];
                }
                else {
                    dp[j] = min(dp[j - 1], dp[j]) + triangle[i][j];
                }
            }
        }
        int res = INT_MAX;
        for(int i = 0; i < triangle.size(); i++)
            res = min(res, dp[i]);
        return res;
    }
};
