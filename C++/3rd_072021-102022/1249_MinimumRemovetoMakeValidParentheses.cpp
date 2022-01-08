//
// Created by BrandonZu on 11/3/21.
//

#include "common.h"

// Runtime 20ms(>90%) | Memory Usage 12MB(>50%)
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n = s.size();
        stack<int> stk;
        vector<bool> use(n, true);
        for(int i = 0; i < n; i++) {
            if(s[i] == '(') {
                stk.push(i);
            }
            else if(s[i] == ')') {
                if(stk.empty())
                    use[i] = false;
                else
                    stk.pop();
            }
        }
        while(!stk.empty()) {
            use[stk.top()] = false;
            stk.pop();
        }
        string res;
        for(int i = 0; i < n; i++) {
            if(use[i])
                res.push_back(s[i]);
        }
        return res;
    }
};

// Runtime 20ms(>90%) | Memory Usage 10.3MB(>93%)
class Solution_2 {
public:
    string minRemoveToMakeValid(string s) {
        int n = s.size();
        stack<int> stk;
        for(int i = 0; i < n; i++) {
            if(s[i] == '(') {
                stk.push(i);
            }
            else if(s[i] == ')') {
                if(stk.empty())
                    s[i] = '!';
                else
                    stk.pop();
            }
        }
        while(!stk.empty()) {
            s[stk.top()] = '!';
            stk.pop();
        }
        s.erase(remove(s.begin(), s.end(), '!'), s.end());
        return s;
    }
};

// 1st Review 12/12/21
// Runtime 20ms(>88%) | Memory Usage 10.2MB(>94%)
class Solution_R1 {
public:
    string minRemoveToMakeValid(string s) {
        int n = s.size();
        stack<int> stk;
        for(int i = 0; i < n; i++) {
            if(s[i] == '(') {
                stk.push(i);
            }
            else if(s[i] == ')') {
                if(stk.empty())
                    s[i] = '!';
                else
                    stk.pop();
            }
        }
        while(!stk.empty()) {
            s[stk.top()] = '!';
            stk.pop();
        }
        s.erase(remove(s.begin(), s.end(), '!'), s.end());
        return s;
    }
};