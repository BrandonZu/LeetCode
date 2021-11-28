//
// Created by BrandonZu on 11/27/21.
//

#include "common.h"

// Runtime 148ms(>84%) | Memory Usage 96MB(>89%)
class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int flag = 0;
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] > nums[i - 1]) {
                if(flag == -1) return false;
                flag = 1;
            }
            else if(nums[i] < nums[i - 1]) {
                if(flag == 1) return false;
                flag = -1;
            }
        }
        return true;
    }
};
