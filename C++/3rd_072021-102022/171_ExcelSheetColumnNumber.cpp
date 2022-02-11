//
// Created by BrandonZu on 2/11/22.
//

#include "common.h"

// Runtime 0ms(>100%) | Memory Usage 5.8MB(>92%s)
class Solution {
public:
    int titleToNumber(string columnTitle) {
        int ans = 0;
        for(char c: columnTitle) {
            ans *= 26;
            ans += c - 'A' + 1;
        }
        return ans;
    }
};