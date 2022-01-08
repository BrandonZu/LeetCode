//
// Created by BrandonZu on 12/12/21.
//

#include "common.h"

// Runtime 148ms(>81%) | Memory Usage 53MB(>27%)
class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        int n = nums.size();
        int max_len = 0;
        vector<int> pref_sum(n, 0);
        unordered_map<int, int> sum_map;
        sum_map[0] = -1;
        pref_sum[0] = nums[0];
        for(int i = 1; i < n; i++) {
            pref_sum[i] = pref_sum[i - 1] + nums[i];
        }
        for(int i = 0; i < n; i++) {
            int target = pref_sum[i] - k;
            if(sum_map.find(target) != sum_map.end()) {
                max_len = max(max_len, i - sum_map[target]);
            }
            if(sum_map.find(pref_sum[i]) == sum_map.end()) {
                sum_map[pref_sum[i]] = i;
            }
        }
        return max_len;
    }
};
