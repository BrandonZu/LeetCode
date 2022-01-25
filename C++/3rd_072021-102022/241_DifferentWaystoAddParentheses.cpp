//
// Created by BrandonZu on 1/25/22.
//

#include "common.h"

// Runtime 0ms(>100%) | Memory Usage 7.5MB(>74%)
class Solution {
public:
    vector<string> expr;
    unordered_map<int, vector<int>> exprMap;
    vector<int> recur(int l, int r) {
        if(exprMap.find(l * 100 + r) != exprMap.end()) {
            return exprMap[l * 100 + r];
        }
        if(l == r) {
            return {stoi(expr[l])};
        }
        vector<int> ret;
        for(int i = l + 1; i < r; i += 2) {
            auto left = recur(l, i - 1), right = recur(i + 1, r);
            for(int x: left) {
                for(int y: right) {
                    if(expr[i] == "+") {
                        ret.push_back(x + y);
                    }
                    else if(expr[i] == "-") {
                        ret.push_back(x - y);
                    }
                    else {
                        ret.push_back(x * y);
                    }
                }
            }
        }
        exprMap[l * 100 + r] = ret;
        return ret;
    }

    vector<int> diffWaysToCompute(string s) {

        for(int i = 0; i < s.size(); i++) {
            if(isdigit(s[i])) {
                int j = i, tmp = 0;
                while(j < s.size() && isdigit(s[j])) {
                    tmp *= 10;
                    tmp += s[j] - '0';
                    j++;
                }
                i = j - 1;
                expr.push_back(to_string(tmp));
            }
            else {
                expr.push_back(s.substr(i, 1));
            }
        }
        return recur(0, expr.size() - 1);
    }
};
