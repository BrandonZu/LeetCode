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

// Runtime 8ms(>92%) | Memory Usage 10.6MB(>14%)
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

// 1st Review 8/15/2021
// Runtime 4ms(>99%) | Memory Usage 10.6MB(>14%)
class Solution_R1 {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size() + 1, INT_MAX);
        dp[0] = INT_MIN;
        int maxLen = 0;
        for(int i = 0; i < nums.size(); i++) {
            int l = 0, r = maxLen;
            while(l < r) {
                int mid = l + r + 1 >> 1;
                if(dp[mid] < nums[i]) {
                    l = mid;
                }
                else {
                    r = mid - 1;
                }
            }
            maxLen = max(maxLen, l + 1);
            dp[l + 1] = nums[i];
        }
        return maxLen;
    }
};

// 2nd Review 10/16/2021
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = INT_MIN;
        int max_len = 0;
        for(int i = 0; i < n; i++) {
            int l = 0, r = max_len;
            while(l < r) {
                int mid = l + r + 1>> 1;
                if(dp[mid] < nums[i]) {
                    l = mid;
                }
                else {
                    r = mid - 1;
                }
            }
            max_len = max(max_len, l + 1);
            dp[l + 1] = nums[i];
        }
        return max_len;
    }
};