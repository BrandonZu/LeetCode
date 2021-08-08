//
// Created by BrandonZu on 2021/8/8.
//

#include "common.h"

// Runtime 64ms(>47%) | Memory Usage 48MB(>77%)
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int max_jump = 0;
        int pos = 0;
        while(pos <= max_jump) {
            max_jump = max(max_jump, pos + nums[pos]);
            if(max_jump >= nums.size() - 1)
                return true;
            pos++;
        }
        return max_jump >= nums.size() - 1;
    }
};
