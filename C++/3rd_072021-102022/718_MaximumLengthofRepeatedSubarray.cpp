//
// Created by BrandonZu on 2021/8/15.
//

#include "common.h"

// DP
// nums1[i] == nums2[j] -> dp[i][j] = d[i - 1][j - 1] + 1
// nums1[i] != nums2[j] -> dp[i][j] = 0

// Runtime 216ms(>78%) | Memory Usage 11.7MB(>92.7%)
class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() < nums2.size()) return findLength(nums2, nums1);
        vector<int> dp(nums2.size() + 1, 0);
        int max_len = 0;
        for(int i = 0; i < nums1.size(); i++) {
            for(int j = nums2.size() - 1; j >= 0; j--) {
                if(nums1[i] == nums2[j]) {
                    dp[j + 1] = dp[j] + 1;
                    max_len = max(max_len, dp[j + 1]);
                }
                else
                    dp[j + 1] = 0;
            }
        }
        return max_len;
    }
};
