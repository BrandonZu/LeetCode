//
// Created by BrandonZu on 2021/8/15.
//

#include "common.h"

// Runtime 8ms(>92%) | Memory Usage 11MB(>60%)
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int dp = 1, maxLen = 1;
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] > nums[i - 1]) {
                dp += 1;
                maxLen = max(maxLen, dp);
            }
            else
                dp = 1;
        }
        return maxLen;
    }
};
