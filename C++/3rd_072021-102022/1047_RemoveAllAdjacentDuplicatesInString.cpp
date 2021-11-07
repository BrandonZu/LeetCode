//
// Created by BrandonZu on 2021/7/17.
//

#include "common.h"

// Runtime 24ms(>51%) | Memory usage 11.5MB(>22%)
class Solution_stack {
public:
    string removeDuplicates(string s) {
        stack<char> remove;
        for(auto c : s) {
            if(!remove.empty() && remove.top() == c)
                remove.pop();
            else
                remove.push(c);
        }
        string result;
        while(!remove.empty()) {
            result += remove.top();
            remove.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }
};

// Runtime 12ms(>98%) | Memory Usage 1MB(>60%)
class Solution_TwoPointers {
public:
    string removeDuplicates(string s) {

        int i, j;
        for(i = 0, j = 0; j < s.size(); ++i, ++j) {
            s[i] = s[j];
            if(i > 0 && s[i] == s[i - 1])
                i -= 2;
        }

        return s.substr(0, i);
    }
};
