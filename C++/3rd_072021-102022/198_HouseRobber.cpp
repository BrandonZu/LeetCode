//
// Created by BrandonZu on 2021/8/10.
//

#include "common.h"

// Runtime 0ms(>100%) | Memory Usage 7.7MB(>41%)
class Solution {
public:
    int rob(vector<int>& nums) {
        int dp_0 = 0, dp_1 = 0;
        for(int i = 1; i <= nums.size(); i++) {
            int pre_0 = dp_0;
            dp_0 = max(dp_0, dp_1);
            dp_1 = pre_0 + nums[i - 1];
        }
        return max(dp_0, dp_1);
    }
};
