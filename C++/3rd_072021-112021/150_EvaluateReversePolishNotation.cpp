//
// Created by BrandonZu on 2021/7/17.
//

#include "common.h"

// Runtime 8ms(>89%) | Memory Usage 12MB(>55%)
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        unordered_map<string, function<int (int, int)>> operMap = {
                {"+", [] (int a, int b) { return a + b; }},
                {"-", [] (int a, int b) { return a - b; }},
                {"*", [] (int a, int b) { return a * b; }},
                {"/", [] (int a, int b) { return a / b; }},
        };
        stack<int> stk;
        for(string ch: tokens) {
            if(operMap.find(ch) != operMap.end()) {
                int num1 = stk.top();
                stk.pop();
                int num2 = stk.top();
                stk.pop();
                stk.push(operMap[ch](num2, num1));
            }
            else {
                int num = stoi(ch);
                stk.push(num);
            }
        }
        return stk.top();
    }
};
