//
// Created by BrandonZu on 2021/7/18.
//

#include "common.h"

// Runtime 4ms(>84%) | Memory Usage 10MB(>53%)
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while(l < r) {
            int mid = (l + r + 1) / 2;
            if(nums[mid] >= target)
                l = mid;
            else
                r = mid - 1;
        }
        if(nums[l] >= target)
            return l + 1;
        else
            return l;
    }
};
