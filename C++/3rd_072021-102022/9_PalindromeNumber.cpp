//
// Created by BrandonZu on 2021/8/10.
//
#include "common.h"

// Runtime 0ms(>100%) | Memory Usage 5.9MB(>72%)
class Solution {
public:
    bool isPalindrome(int x) {
        int flag = x >= 0 ? 1 : -1;
        long rever = 0, tmp = x;
        while(tmp) {
            rever *= 10;
            rever += tmp % 10;
            tmp /= 10;
        }
        return rever * flag == x;
    }
};

