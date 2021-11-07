//
// Created by BrandonZu on 10/30/21.
//

#include "common.h"

// Runtime 0ms(>100%) | Memory Usage 9MB(>51%)
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while(l < r) {
            int mid = (l + r) / 2;
            if(nums[mid + 1] > nums[mid]) {
                l = mid + 1;
            }
            else {
                r = mid;
            }
        }
        return l;
    }
};
