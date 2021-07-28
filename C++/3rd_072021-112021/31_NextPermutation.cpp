//
// Created by BrandonZu on 2021/7/26.
//

#include "common.h"

// Runtime 4ms(>80%) | Memory Usage 12MB(>35%)
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.size() <= 1) return;
        int pos = nums.size() - 1;
        while(pos > 0 && nums[pos] <= nums[pos - 1])
            pos--;

        if(pos == 0) {
            reverse(nums.begin(), nums.end());
            return;
        }

        int cur = pos - 1;
        while(pos < nums.size() && nums[pos] > nums[cur])
            pos++;
        swap(nums[cur], nums[pos - 1]);
        reverse(nums.begin() + cur + 1, nums.end());
    }
};
