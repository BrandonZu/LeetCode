//
// Created by BrandonZu on 2021/7/26.
//

#include "common.h"

// Runtime 112ms(>87%) | Memory Usage 63MB(>72%)
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> stk;
        int result = 0;
        // Add a sentinel to the head and the end
        heights.push_back(0);   // Height
        stk.push(-1);   // Index
        // Maintain a decreasing monotonic stack
        for(int i = 0; i < heights.size(); i++) {
            // Because of the sentinel, stk.size() should be more than 1
            while(stk.size() > 1 && heights[stk.top()] > heights[i]) {
                int curHeight = heights[stk.top()];
                stk.pop();
                result = max(result, (i - stk.top() - 1) * curHeight);
            }
            stk.push(i);
        }
        return result;
    }
};
