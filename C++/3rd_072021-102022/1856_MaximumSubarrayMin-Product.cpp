//
// Created by BrandonZu on 2/9/22.
//

#include "common.h"

// Runtime 459ms(>19%) | Memory Usage 96MB(>22%)
class Solution {
public:
    const long MOD = 1e9 + 7;
    int maxSumMinProduct(vector<int>& nums) {
        int n = nums.size();
        vector<long> pref_sum(n + 1, 0), left_min(n, -1), right_min(n, n);
        long cur_sum = 0;
        for(int i = 0; i < n; i++) {
            cur_sum += nums[i];
            pref_sum[i + 1] = cur_sum;
        }

        stack<int> stk;
        for(int i = 0; i < n; i++) {
            while(!stk.empty() && nums[i] <= nums[stk.top()]) {
                right_min[stk.top()] = i;
                stk.pop();
            }
            if(stk.empty() || nums[i] >= nums[stk.top()]) {
                if(!stk.empty() && nums[i] > nums[stk.top()]) {
                    left_min[i] = stk.top();
                }
                stk.push(i);
            }
        }

        long result = 0;
        for(int i = 0; i < n; i++) {
            result = max(result, (long)nums[i] * (pref_sum[right_min[i] - 1 + 1] - pref_sum[left_min[i] + 1]));
        }
        return result % MOD;
    }
};
