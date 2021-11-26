//
// Created by BrandonZu on 11/25/21.
//

#include "common.h"

// Loop Invariant: a + b * (next_num)
// 下一个运算符是加号，那么 a+b×(c) + (next_num) = (a+b×c)+1×(next_num);
// 下一个运算符是减号，那么 a+b×(c) − (next_num) = (a+b×c)+(−1)×(next_num);
// 下一个运算符是乘号，那么 a+b×(c) × (next_num) = a+(b×c)×(next_num);

// Runtime 54ms(>94%) | Memory Usage 14.7MB(>92%)
class Solution {
    string path;
    vector<string> res;
public:
    vector<string> addOperators(string num, int target) {
        path.resize(30);
        backtrack(num, 0, 0, 0, 1, target);
        return res;
    }

    void backtrack(const string& num, int numPos, int pathPos, long a, long b, int target) {
        if(numPos == num.size()) {
            if(a == target)
                res.push_back(path.substr(0, pathPos - 1));
            return;
        }
        long c = 0;
        for(int i = numPos; i < num.size(); i++) {
            if(i > numPos && num[numPos] == '0') break; // Remove Leading zeros
            c = c * 10 + num[i] - '0';
            path[pathPos++] = num[i];

            path[pathPos] = '+'; // Add a '+' in the end so that if the value of 'num' itself equals target
            backtrack(num, i + 1, pathPos + 1, a + b * c, 1, target);

            if(i + 1 < num.size()) {
                path[pathPos] = '-';
                backtrack(num, i + 1, pathPos + 1, a + b * c, -1, target);
            }
            if(i + 1 < num.size()) {
                path[pathPos] = '*';
                backtrack(num, i + 1, pathPos + 1, a, b * c, target);
            }
        }
    }
};
