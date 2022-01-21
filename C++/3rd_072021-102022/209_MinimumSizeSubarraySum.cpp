//
// Created by BrandonZu on 1/20/22.
//

#include "common.h"

// Runtime 12ms(>38%) | Memory Usage 10.5MB(>93%)
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int max_len = 1e6;
        int l = 0, r = 0;
        int cur_sum = 0;
        while(r < nums.size()) {
            while(r < nums.size() && cur_sum < target) {
                cur_sum += nums[r];
                r++;
            }
            while(l < r && cur_sum >= target) {
                max_len = min(max_len, r - l);
                cur_sum -= nums[l];
                l++;
            }
        }
        return max_len == 1e6 ? 0 : max_len;
    }
};
