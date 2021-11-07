//
// Created by BrandonZu on 2021/7/18.
//

#include "common.h"

// Runtime 0ms(>100%) | Memory Usage 11MB(>28%)
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        // Find Peak
        while(l < r) {
            int mid = l + r + 1 >> 1;
            if(nums[mid] > nums[0])
                l = mid;
            else
                r = mid - 1;
        }
        int peak = l;
        // Attention! This comparison includes the corner case where nums.size == 1
        if(target >= nums[0])
            l = 0, r = peak;
        else
            l = peak + 1, r = nums.size() - 1;
        while(l <= r) {
            int mid = l + r >> 1;
            if(nums[mid] == target)
                return mid;
            else if(nums[mid] > target)
                r = mid - 1;
            else
                l = mid + 1;
        }
        return -1;
    }
};
