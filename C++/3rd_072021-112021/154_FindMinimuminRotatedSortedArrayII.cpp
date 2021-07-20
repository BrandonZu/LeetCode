//
// Created by BrandonZu on 2021/7/19.
//

#include "common.h"

// Runtime 4ms(>92%) | Memory Usage 12MB(>9%)
class Solution {
public:
    int findMin(vector<int>& nums) {
        int sz = nums.size() - 1;
        // Remove Duplicates
        while(sz > 0 && nums[sz] == nums[0])
            sz--;
        // Corner Case
        if(nums[sz] >= nums[0]) return nums[0];
        // Binary Search
        int l = 0, r = sz;
        while(l < r) {
            int mid = l + r >> 1;
            if(nums[mid] < nums[0])
                r = mid;
            else
                l = mid + 1;
        }
        return nums[l];
    }
};
