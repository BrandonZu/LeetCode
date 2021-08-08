//
// Created by BrandonZu on 2021/8/8.
//

#include "common.h"

// Runtime 264ms(>42%) | Memory Usage 10.5MB(>61%)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size() + 2, 1);
        for(int i = 1; i < nums.size(); i++) {
            for(int j = 0; j < i; j++) {
                if(nums[j] < nums[i])
                    dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        int res = 0;
        for(int x: dp)
            res = max(res, x);
        return res;
    }
};
