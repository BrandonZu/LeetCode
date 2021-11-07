//
// Created by BrandonZu on 2021/8/3.
//
#include "common.h"

// Runtime 148mn(>51%) | Memory Usage 9MB(>97%)
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total = 0;
        for(int x: nums)
            total += x;
        if(total % 2) return false;
        int target = total / 2;
        vector<bool> dp(target + 1, false);
        dp[0] = true;
        for(int i = 1; i <= nums.size(); i++) {
            for(int j = target; j >= nums[i - 1]; j--) {
                dp[j] = dp[j] || dp[j - nums[i - 1]];
            }
        }
        return dp[target];
    }
};
