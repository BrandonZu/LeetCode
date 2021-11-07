//
// Created by BrandonZu on 2021/8/24.
//

#include "common.h"

// Runtime 3ms(>82%) | Memory Usage 7.3MB(>40%)
class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> stk;
        int res = 0;

        for(int i = 0, pre = -1; i < s.size(); i++) {
            if(s[i] == '(') {
                stk.push(i);
            }
            else {
                if(stk.empty()) {
                    pre = i;
                    continue;
                }
                stk.pop();
                if(stk.empty()) {
                    res = max(res, i - pre);
                }
                else {
                    res = max(res, i - stk.top());
                }
            }
        }
        return res;
    }
};
