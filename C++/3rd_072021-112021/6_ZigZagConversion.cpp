//
// Created by BrandonZu on 2021/8/4.
//

#include "common.h"

// Runtime 12ms(>63.66%) | Memory Usage 8.1MB(>92%)
class Solution {
public:
    string convert(string s, int numRows) {
        int len = numRows * 2 - 2;
        if(len == 0)
            return s;
        string res;
        for(int i = 0; i < numRows; i++) {
            if(i == 0 || i == numRows - 1) {
                for(int j = i; j < s.size(); j += len)
                    res += s[j];
            }
            else {
                for(int j = i; j < s.size(); j += len) {
                    res += s[j];
                    if(j - i + len - i < s.size())
                        res += s[j - i + len - i];
                }
            }
        }
        return res;
    }
};

