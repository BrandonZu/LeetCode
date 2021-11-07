//
// Created by BrandonZu on 2021/8/13.
//

#include "common.h"

// Runtime 7ms(>48%) | Memory Usage 13MB(>91%)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = 0, cur = 0;
        for(int num: nums) {
            cur += num;
            res = max(res, cur);
            if(cur < 0)
                cur = 0;
        }
        if(res <= 0)
            return *max_element(nums.begin(), nums.end());
        else
            return res;
    }
};
