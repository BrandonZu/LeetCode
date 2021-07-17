//
// Created by BrandonZu on 2021/7/17.
//

#include "common.h"


// Runtime 0ms(>100%) | Memory Usage 6.3MB(>77%)
class Solution {
public:
    bool isValid(string s) {
        stack<char> match;
        for(auto c : s) {
            if(c == '(' || c == '{' || c == '[') {
                match.push(c);
            }
            else if(c == ')') {
                if(match.empty() || match.top() != '(')
                    return false;
                else
                    match.pop();
            }
            else if(c == ']') {
                if(match.empty() || match.top() != '[')
                    return false;
                else
                    match.pop();
            }
            else if(c == '}') {
                if(match.empty() || match.top() != '{')
                    return false;
                else
                    match.pop();
            }
            else
                throw exception();
        }
        // WARNING!! MUST RETURN THE STATE OF MATCH!!
        return match.empty();
    }
};

