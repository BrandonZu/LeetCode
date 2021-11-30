//
// Created by BrandonZu on 11/30/21.
//

#include "common.h"

// Runtime 16ms(>97%) | Memory Usage 31MB(>28%)
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = 0;
        for(int i: nums)
            sum += i;
        int i;
        int l = 0, r = sum;
        for(i = 0; i < nums.size(); i++) {
            r -= nums[i];
            if(l == r) {
                return i;
            }
            l += nums[i];
        }
        return -1;
    }
};
