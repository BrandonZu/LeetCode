//
// Created by BrandonZu on 11/3/21.
//

#include "common.h"

// Runtime 88ms(>57%) | Memory Usage 43MB(>11%)
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> prev_sum(n, 0);
        prev_sum[0] = nums[0];
        for(int i = 1; i < n; i++) {
            prev_sum[i] = prev_sum[i - 1] + nums[i];
        }
        unordered_map<int, int> sum_map;
        sum_map[0] = 1;
        int ans = 0;
        for(int i = 0; i < n; i++) {
            ans += sum_map[prev_sum[i] - k];
            sum_map[prev_sum[i]]++;
        }
        return ans;
    }
};
