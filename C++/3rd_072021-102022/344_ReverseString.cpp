//
// Created by BrandonZu on 2021/7/23.
//

#include "common.h"

// Runtime 16ms(>80%) | Memory Usage 23MB(>95%)
class Solution {
public:
    void reverseString(vector<char>& s) {
        int l = 0, r = s.size() - 1;
        while(l < r)
            swap(s[l++], s[r--]);
    }
};

