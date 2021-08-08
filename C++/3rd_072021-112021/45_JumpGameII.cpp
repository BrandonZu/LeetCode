//
// Created by BrandonZu on 2021/8/8.
//

#include "common.h"

// DP[] Monotonically Increasing

// Runtime 1240ms(>5%) | Memory Usage 17MB(>24%)
class Solution_DP {
public:
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size() + 1, 1001);
        dp[0] = 0;
        for(int i = 0; i < nums.size(); i++) {
            for(int j = 0; j < i; j++) {
                if(j + nums[j] >= i) {
                    dp[i] = min(dp[i], dp[j] + 1);
                }
            }
        }
        return dp[nums.size() - 1];
    }
};

// Runtime 12ms(>85%) | Memory Usage 16.3MB(>89%)
class Solution_BFS {
public:
    int jump(vector<int>& nums) {
        int start = 0, end = 0, step = 0, max_jump= 0, sz = nums.size();
        while(end < sz - 1) {
            step++;
            for(int i = start; i <= end; i++) {
                max_jump = max(max_jump, i + nums[i]);
            }
            start = end + 1;
            end = max_jump;
        }
        return step;
    }
};
