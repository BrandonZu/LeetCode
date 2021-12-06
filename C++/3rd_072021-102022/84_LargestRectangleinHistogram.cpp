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
        // Maintain a increasing monotonic stack
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

// 1st Review 12/5/2021
// Runtime 128ms(>60%) | Memory Usage 63MB(>50%)
class Solution_R1 {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> stk;
        heights.push_back(0);
        int max_area = 0;
        int pos = 0;
        while(pos < heights.size()) {
            while(!stk.empty() && heights[pos] < heights[stk.top()]) {
                int cur_h = heights[stk.top()];
                stk.pop();
                if(stk.empty()) {
                    max_area = max(max_area, pos * cur_h);
                }
                else {
                    max_area = max(max_area, (pos - stk.top() - 1) * cur_h);
                }
            }
            stk.push(pos);
            pos++;
        }
        return max_area;
    }
};
