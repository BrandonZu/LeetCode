//
// Created by BrandonZu on 11/14/21.
//

#include "common.h"

// Runtime 0ms(>100%) | Memory Usage 6MB(>96%)
class Solution {
public:
    string customSortString(string order, string s) {
        int val[26] = {};
        for(int i = 0; i < order.size(); i++) {
            val[order[i] - 'a'] = i + 1;
        }
        sort(s.begin(), s.end(), [&](char a, char b) {
            return val[a - 'a'] < val[b - 'a'];
        });
        return s;
    }
};
