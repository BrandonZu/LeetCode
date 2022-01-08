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

// 1st Review
// Runtime 76ms(>69%) | Memory Usage 36MB(>63%)
class Solution_R1 {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int cnt = 0;
        unordered_map<int, int> pref_map;
        pref_map[0]++;
        for(int i = 0, cur = 0; i < n; i++) {
            cur += nums[i];
            if(pref_map.find(cur - k) != pref_map.end()) {
                cnt += pref_map[cur - k];
            }
            pref_map[cur]++;
        }
        return cnt;
    }
};