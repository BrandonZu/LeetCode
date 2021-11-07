//
// Created by BrandonZu on 2021/8/2.
//
#include "common.h"

// DP Transfer Function
// dp[i] = dp[i - 1] + dp[i - 2]
// Using Scrolling Array

// Runtime 0ms(>100%) | Memory Usage 5.9MB(>82%)
class Solution {
public:
    int climbStairs(int n) {
        if(n < 2) return 1;
        int ll = 1, l = 1;
        int cur = 2;
        for(int i = 2; i <= n; i++) {
            cur = ll + l;
            ll = l;
            l = cur;
        }
        return cur;
    }
};
