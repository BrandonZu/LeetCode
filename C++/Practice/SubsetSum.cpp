//
// Created by BrandonZu on 3/30/22.
//

#include "common.h"

bool subsetSum(vector<int>& nums, int t) {
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(t, false));
    for(int i = 0; i < n; i++) {
        dp[i][0] = true;
    }
    for(int i = 0; i < n; i++) {
        for(int j = nums[i]; j < t; j++) {
            dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i]];
        }
    }
    return dp[n][t];
}
