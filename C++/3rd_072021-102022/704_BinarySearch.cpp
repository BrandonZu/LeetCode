//
// Created by BrandonZu on 2021/7/18.
//

#include "common.h"

// Runtime 36ms(>67%) | Memory Usage 27.5MB(>91%)
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size();
        while(l <= r) {
            int mid = l + (r - l) / 2;
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
