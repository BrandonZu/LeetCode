//
// Created by BrandonZu on 2021/8/1.
//

#include "common.h"

// Runtime 0ms(>100%) | Memory Usage 11.8MB(>74%)
class Solution {
public:
    vector<string> result;
    string path;

    void backtrack(int l_cnt, int r_cnt, int n) {
        if(l_cnt == n && r_cnt == n) {
            result.push_back(path);
            return;
        }
        // Add Left Parenthesis
        if(l_cnt < n) {
            path.push_back('(');
            backtrack(l_cnt + 1, r_cnt, n);
            path.pop_back();
        }
        // Add Right Parenthesis
        if(r_cnt < l_cnt) {
            path.push_back(')');
            backtrack(l_cnt, r_cnt + 1, n);
            path.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        backtrack(0, 0, n);
        return result;
    }
};
