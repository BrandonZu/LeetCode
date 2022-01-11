//
// Created by BrandonZu on 1/11/22.
//

#include "common.h"

// Runtime 28ms(>76%) | Memory Usage 25MB(>93%)
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;
        if(!k) return;
        reverse(nums.begin(), nums.begin() + n - k);
        reverse(nums.begin() + n - k, nums.end());
        reverse(nums.begin(), nums.end());
    }
};
