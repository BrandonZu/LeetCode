//
// Created by BrandonZu on 11/7/21.
//

#include "common.h"

// Runtime 20ms(>26%) | Memory Usage 8MB(>77%)
class Solution {
    unordered_map<char, int> oper_priority;
public:
    Solution() {
        oper_priority = {
                {'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}
        };
    }

    void eval(stack<int>& num, stack<char>& oper) {
        int num2 = num.top(); num.pop();
        int num1 = num.top(); num.pop();
        char op = oper.top(); oper.pop();
        switch (op) {
            case '+': num.push(num1 + num2); break;
            case '-': num.push(num1 - num2); break;
            case '*': num.push(num1 * num2); break;
            case '/': num.push(num1 / num2); break;
        }
    }

    int calculate(string s) {
        stack<int> num;
        stack<char> oper;

        for(int i = 0; i < s.size(); i++) {
            if(isdigit(s[i])) {
                int cur_num = 0;
                while(i < s.size() && isdigit(s[i])) {
                    cur_num *= 10;
                    cur_num += s[i] - '0';
                    i++;
                }
                num.push(cur_num);
                i--;
            }
            else if(!isspace(s[i])) {
                while(!oper.empty() && oper_priority[oper.top()] >= oper_priority[s[i]]) {
                    eval(num, oper);
                }
                oper.push(s[i]);
            }
        }
        while(!oper.empty()) {
            eval(num, oper);
        }
        return num.top();
    }
};
