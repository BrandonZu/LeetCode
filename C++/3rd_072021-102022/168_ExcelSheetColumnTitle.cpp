//
// Created by BrandonZu on 2/11/22.
//

#include "common.h"

// Runtime 2ms(>25%) | Memory Usage 6MB(>46%)
class Solution {
public:
    string convertToTitle(int columnNumber) {
        const int exp = 26;
        string res;
        while(columnNumber) {
            columnNumber -= 1;
            res += 'A' + columnNumber % exp;
            columnNumber /= exp;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
