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

// 1st Review 08/13/2021
// Runtime 56ms(>77%) | Memory Usage 48.4MB(>42%)
class Solution_R1 {
public:
    bool canJump(vector<int>& nums) {
        int maxPos = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(i > maxPos)
                return false;
            maxPos = max(maxPos, i + nums[i]);
        }
        return maxPos >= nums.size() - 1;
    }
};