//
// Created by BrandonZu on 11/8/21.
//

#include "common.h"

// Runtime 0ms(>100%) | Memory Usage 6.3MB(>19%)
class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> stk;

        for(char c: s) {
            if(c == '(') {
                stk.push('(');
            }
            else if(c == ')') {
                if(!stk.empty() && stk.top() == '(')
                    stk.pop();
                else
                    stk.push(')');
            }
        }
        return (int)stk.size();
    }
};

// Runtime 0ms(>100%) | Memory Usage 6.1MB(>79%)
class Solution_OP {
public:
    int minAddToMakeValid(string s) {
        int leftBracketNeeded = 0, rightBracketNeeded = 0;
        for(char c: s) {
            if(c == '(') {
                rightBracketNeeded++;
            }
            else {
                if(rightBracketNeeded > 0)
                    rightBracketNeeded--;
                else
                    leftBracketNeeded++;
            }
        }
        return leftBracketNeeded + rightBracketNeeded;
    }
};
