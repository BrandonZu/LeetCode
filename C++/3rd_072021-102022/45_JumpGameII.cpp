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

// 1st Review 08/14/2021
// Runtime 11ms(>88%) | Memory Usage 16.4MB(>64%)
class Solution_R1 {
public:
    int jump(vector<int>& nums) {
        int l = 0, r = 0, maxJump = 0;
        int res = 0;
        while(r < (int)nums.size() - 1) {
            res++;
            for(int i = l; i <= r; i++)
                maxJump = max(maxJump, i + nums[i]);
            l = r + 1;
            r = maxJump;
        }
        return res;
    }
};

// R .25 | M .29
class Solution3_1 {
public:
    int jump(vector<int>& nums) {
        vector<int> steps(nums.size(), nums.size() + 1);
        steps[0] = 0;
        for(int i = 0; i < nums.size(); i++) {
            for(int j = i + 1; j <= i + nums[i] && j < nums.size(); j++) {
                steps[j] = min(steps[j], steps[i] + 1);
            }
        }
        return steps.back();
    }
};

// R .87 | M .54
class Solution3_2 {
public:
    int jump(vector<int>& nums) {
        int steps = 0;
        int cover = 0, nextCover = 0;
        for(int i = 0; i < nums.size() && cover < nums.size() - 1; i++) {
            if(i > cover) {
                ++steps;
                cover = nextCover;
            }
            nextCover = max(nextCover, i + nums[i]);
        }
        return steps;
    }
};
