//
// Created by BrandonZu on 2/18/22.
//

#include "common.h"

// Runtime 212ms(>54%) | Memory Usage 9.2MB(>36%)
class Solution {
public:
    int numSquares(int n) {
        int bags = floor(sqrt(n));
        vector<int> nums(bags);
        for(int i = 0; i < nums.size(); i++) {
            nums[i] = (i + 1) * (i + 1);
        }
        vector<int> dp(n + 1, INT_MAX / 2);
        dp[0] = 0;
        for(int i = 0; i < bags; i++) {
            for(int j = nums[i]; j <= n; j++) {
                dp[j] = min(dp[j], dp[j - nums[i]] + 1);
            }
        }
        return dp[n];
    }
};
