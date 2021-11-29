//
// Created by BrandonZu on 11/28/21.
//

#include "common.h"

// Runtime 28ms(>59%) | Memory Usage 10MB(>67%)
class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char, int>> stk;
        for(char c: s) {
            if(stk.empty() || stk.top().first != c) {
                stk.push({c, 1});
            }
            else {
                stk.top().second++;
                if(stk.top().second >= k)
                    stk.pop();
            }
        }
        string res;
        while(!stk.empty()) {
            for(int i = 0; i < stk.top().second; i++) {
                res.push_back(stk.top().first);
            }
            stk.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
