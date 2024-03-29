//
// Created by BrandonZu on 2021/7/28.
//

#include "common.h"

// Monotonic Stack
// Runtime 4ms(>90%) | Memory Usage 14.5MB(>10%)
class Solution_Stack {
public:
    int trap(vector<int>& height) {
        stack<int> stk;
        int res = 0;
        for(int i = 0; i < height.size(); i++) {
            while(!stk.empty() && height[stk.top()] < height[i]) {
                int curH = height[stk.top()];
                stk.pop();
                if(stk.empty()) break;
                res += (i - stk.top() - 1) * (min(height[i], height[stk.top()]) - curH);
            }
            stk.push(i);
        }
        return res;
    }
};

// DP
// Runtime 4ms(>90%) | Memory Usage 14.6MB(>10%)
class Solution_DP {
public:
    int trap(vector<int>& height) {
        int left = 0;
        vector<int> right(height.size() + 1, 0);

        for(int i = height.size() - 2; i >= 0; i--) {
            right[i] = max(height[i + 1], right[i + 1]);
        }

        int res = 0;
        for(int i = 0; i < height.size(); i++) {
            if(min(left, right[i]) - height[i] > 0)
                res += min(left, right[i]) - height[i];
            left = max(left, height[i]);
        }

        return res;
    }
};

// Two Pointers
// Runtime 4ms(>90%) | Memory Usage 14MB(97%)
class Solution_TwoPointers {
public:
    int trap(vector<int>& height) {
        int res = 0;
        int l_max = 0, r_max = 0;
        int l = 0, r = height.size() - 1;

        while(l <= r) {
            if(l_max < r_max) {
                res += max(0, l_max - height[l]);
                l_max = max(l_max, height[l]);
                l++;
            }
            else {
                res += max(0, r_max - height[r]);
                r_max = max(r_max, height[r]);
                r--;
            }
        }

        return res;
    }
};

// 1st Review 11/16/21
// Runtime 8ms(>82%) | Memory Usage 16MB(>31%)
class Solution_Stack_R1 {
public:
    int trap(vector<int>& height) {
        stack<int> stk;
        int res = 0;
        for(int i = 0; i < height.size(); i++) {
            while(!stk.empty() && height[stk.top()] < height[i]) {
                int bot = stk.top();
                stk.pop();
                if(!stk.empty()) {
                    res += (i - stk.top() - 1) * (min(height[stk.top()], height[i]) - height[bot]);
                }
            }
            stk.push(i);
        }
        return res;
    }
};

// 1st Review 11/16/21
// Runtime 8ms(>81%) | Memory Usage 15.7MB(>83%)
class Solution_TwoPointers_R1 {
public:
    int trap(vector<int>& height) {
        int l_max = 0, r_max = 0;
        int l = 0, r = height.size() - 1;
        int res = 0;
        while(l <= r) {
            if(l_max < r_max) {
                res += max(0, l_max - height[l]);
                l_max = max(l_max, height[l]);
                l++;
            }
            else {
                res += max(0, r_max - height[r]);
                r_max = max(r_max, height[r]);
                r--;
            }
        }
        return res;
    }
};

// 2nd Review 12/12/21
// Runtime 8ms(>81%) | Memory Usage 15.7MB(>83%)
class Solution_TwoPointers_R2 {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int l = 0, r = n - 1;
        int l_high = 0, r_high = 0;
        int res = 0;
        while(l <= r) {
            if(l_high < r_high) {
                res += max(0, l_high - height[l]);
                l_high = max(height[l], l_high);
                l++;
            }
            else {
                res += max(0, r_high - height[r]);
                r_high = max(height[r], r_high);
                r--;
            }
        }
        return res;
    }
};

