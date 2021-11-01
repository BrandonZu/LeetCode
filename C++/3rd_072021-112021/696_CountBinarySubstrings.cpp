//
// Created by BrandonZu on 10/31/21.
//

#include "common.h"

// Runtime 20ms(>94%) Memory Usage 12MB(>25%)
class Solution {
public:
    int countBinarySubstrings(string s) {
        s.push_back('!');
        int cur = 1, pre = 0, res = 0;
        for(int i = 1; i < s.size(); i++) {
            if(s[i] == s[i - 1])
                cur++;
            else {
                res += min(cur, pre);
                pre = cur;
                cur = 1;
            }
        }
        return res;
    }
};
