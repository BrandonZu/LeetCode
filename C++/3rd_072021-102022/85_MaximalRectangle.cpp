//
// Created by BrandonZu on 12/5/21.
//

#include "common.h"

// Runtime 36ms(>37%) | Memory Usage 13MB(>26%)
class Solution {
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
        heights.pop_back();
        return max_area;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<int> heights(m);
        int max_area = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(matrix[i][j] == '1') {
                    heights[j]++;
                }
                else {
                    heights[j] = 0;
                }
            }
            max_area = max(max_area, largestRectangleArea(heights));
        }
        return max_area;
    }
};

