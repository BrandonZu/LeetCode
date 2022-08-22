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

// Runtime 47ms(>60%) | Memory Usage 28MB(>30%)
class Solution2 {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l = 0, r = 0;
        int res = nums.size() + 1;
        int cur_sum = 0;
        while(r < nums.size()) {
            cur_sum += nums[r++];
            if(cur_sum >= target) {
                while(cur_sum >= target) {
                    cur_sum -= nums[l++];
                }
                res = min(res, r - l + 1);
            }
        }
        return res == nums.size() + 1 ? 0 : res;
    }
};