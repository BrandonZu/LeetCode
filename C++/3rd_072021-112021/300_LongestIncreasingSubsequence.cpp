//
// Created by BrandonZu on 2021/8/8.
//

#include "common.h"

// Runtime 264ms(>42%) | Memory Usage 10.5MB(>61%)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size() + 2, 1);
        for(int i = 1; i < nums.size(); i++) {
            for(int j = 0; j < i; j++) {
                if(nums[j] < nums[i])
                    dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        int res = 0;
        for(int x: dp)
            res = max(res, x);
        return res;
    }
};

// Runtime 8ms(>92%) | Memory Usage 10.6MB(14%)
class Solution_Optimized1 {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size() + 1);
        int max_len = 0;
        dp[0] = INT_MIN;
        for(int i = 0; i < nums.size(); i++) {
            // Binary Search
            int l = 0, r = max_len;
            while(l < r) {
                int mid = (l + r + 1) >> 1;
                if(dp[mid] < nums[i]) {
                    l = mid;
                }
                else {
                    r = mid - 1;
                }
            }
            dp[l + 1] = nums[i];
            max_len = max(max_len, l + 1);
        }
        return max_len;
    }
};
