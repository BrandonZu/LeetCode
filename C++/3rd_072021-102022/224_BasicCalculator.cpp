//
// Created by BrandonZu on 9/27/21.
//

#include "common.h"

// Runtime 20ms(>29%) | Memory Usage 9.2MB(>25%)
class Solution_1 {
public:
    void cal(stack<int>& nums, stack<char>& oper) {
        char op = oper.top();
        oper.pop();
        int num2 = nums.top();
        nums.pop();
        int num1 = nums.top();
        nums.pop();
        if(op == '+') {
            nums.push(num1 + num2);
        }
        else if(op == '-') {
            nums.push(num1 - num2);
        }
    }

    int calculate(string s) {
        // Remove Spaces
        int j = 0;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == ' ')
                continue;
            else
                s[j++] = s[i];
        }
        stack<int> nums;
        stack<char> oper;
        for(int pos = 0; pos < j; pos++) {
            if(s[pos] == '(') {
                oper.push(s[pos]);
            }
            else if(s[pos] == '-' || s[pos] == '+') {
                // IMPORTANT For unary operator '-'
                if (pos == 0 || s[pos - 1] == '(' || s[pos - 1] == '+' || s[pos - 1] == '-')
                    nums.push(0);
                while(!oper.empty() && oper.top() != '(')
                    cal(nums, oper);
                oper.push(s[pos]);
            }
            else if(s[pos] == ')') {
                while(!oper.empty() && oper.top() != '(')
                    cal(nums, oper);
                oper.pop();
            }
            else if(isdigit(s[pos])) {
                int num = 0;
                while(pos < j && isdigit(s[pos])) {
                    num = num * 10 + (s[pos] - '0');
                    pos++;
                }
                nums.push(num);
                pos--;
            }
        }

        while(!oper.empty()) {
            cal(nums, oper);
        }
        return nums.top();
    }
};

class Solution {
public:
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
            else if(s[i] == '(') {
                oper.push(s[i]);
            }
            else if(s[i] == ')') {
                while(!oper.empty() && oper.top() != '(') {
                    cal(num, oper);
                }
                oper.pop();
            }
            else if(!isspace(s[i])) {
                // Transform unary operator '-' to binary operator by adding a leading 0
                if(s[i] == '-' && (i == 0 || s[i - 1] == '('))
                    num.push(0);
                while(!oper.empty() && oper.top() != '(')
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
    Solution s;
    string tmp = "(1+(4+5+2)-3)+(6+8)";
    cout << s.calculate(tmp) << endl;

}
