//
// Created by BrandonZu on 2021/7/25.
//

#include "common.h"

// Runtime 32ms(>75%) | Memory Usage 23.9MB(>59%)
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        if(nums.empty()) return {};
        stack<int> stk;
        vector<int> result(nums.size(), -1);
        int sz = nums.size();
        // Round 1
        for(int i = 0; i < sz; i++) {
            while(!stk.empty() && nums[i] > nums[stk.top()]) {
                result[stk.top()] = nums[i];
                stk.pop();
            }
            stk.push(i);
        }
        // Round 2
        for(int i = 0; i < sz; i++) {
            while(!stk.empty() && nums[i] > nums[stk.top()]) {
                if(result[stk.top()] == -1)
                    result[stk.top()] = nums[i];
                stk.pop();
            }
            stk.push(i);
        }

        return result;
    }
};
