//
// Created by BrandonZu on 11/7/21.
//

#include "common.h"

// Runtime 4ms(>76%) | Memory Usage 6.8MB(>72%)
class Solution {
    unordered_map<char, int> oper_map;
public:
    Solution() {
        oper_map = {
                {'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}, {'(', 3}
        };
    }

    void cal(stack<int>& num, stack<char>& oper) {
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
        int j = 0;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == ' ')
                continue;
            else
                s[j++] = s[i];
        }

        for(int i = 0; i < j; i++) {
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
            else if(s[i] == ')') {
                while(!oper.empty() && oper.top() != '(') {
                    cal(num, oper);
                }
                oper.pop();
            }
            else {
                if(s[i] == '-' && (i == 0 || s[i - 1] == '('))
                    num.push(0);
                while(!oper.empty() && oper.top() != '(' && oper_map[oper.top()] >= oper_map[s[i]])
                    cal(num, oper);
                oper.push(s[i]);
            }
        }

        while(!oper.empty()) {
            cal(num, oper);
        }

        return num.top();
    }
};

int main() {
    string test = "2*(5+5*2)/3+(6/2+8)";
    Solution s;
    cout << s.calculate(test) << endl;
}

