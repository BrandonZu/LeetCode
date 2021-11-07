//
// Created by BrandonZu on 9/27/21.
//

#include "common.h"

// Runtime 20ms(>29%) | Memory Usage 9.2MB(>25%)
class Solution {
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
                // IMPORTANT
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
                while(pos < s.size() && isdigit(s[pos])) {
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

int main() {
    Solution s;
    string tmp = "(1+(4+5+2)-3)+(6+8)";
    s.calculate(tmp);

}
