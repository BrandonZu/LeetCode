//
// Created by BrandonZu on 10/21/21.
//

#include "common.h"

// Runtime 10ms(>50%) | Memory Usage 15MB(>64%)
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> stk;
        int p_pop = 0;
        for(int i = 0; i < pushed.size(); i++) {
            stk.push(pushed[i]);
            while(!stk.empty() && p_pop < popped.size() && stk.top() == popped[p_pop]) {
                stk.pop();
                p_pop++;
            }
        }
        return stk.empty();
    }
};
