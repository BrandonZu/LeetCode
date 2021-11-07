//
// Created by BrandonZu on 2021/8/11.
//

#include "common.h"

// Runtime 4ms(>43%) | Memory Usage 7.8MB(>55%)
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() < 2)
            return nums[0];
        int dp_0 = 0, dp_1 = 0;
        int res = 0;
        // Rob First Home
        dp_0 = INT_MIN, dp_1 = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            int pre_0 = dp_0;
            dp_0 = max(dp_0, dp_1);
            dp_1 = pre_0 + nums[i];
        }
        res = max(res, dp_0);
        // Don't Rob First Home
        dp_0 = 0, dp_1 = INT_MIN;
        for(int i = 1; i < nums.size(); i++) {
            int pre_0 = dp_0;
            dp_0 = max(dp_0, dp_1);
            dp_1 = pre_0 + nums[i];
        }
        res = max(res, max(dp_0, dp_1));
        return res;
    }
};
