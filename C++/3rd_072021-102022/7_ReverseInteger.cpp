//
// Created by BrandonZu on 2021/8/3.
//

#include "common.h"

// Runtime 0ms(>100%) | Memory Usage 5.9MB(>32%)
class Solution {
public:
    int reverse(int x) {
        long result = 0;
        int flag = x < 0 ? -1 : 1;
        x = abs(x);
        while(x) {
            result *= 10;
            result += x % 10;
            if(flag * result > INT_MAX || flag * result < INT_MIN)
                return 0;

            x /= 10;
        }
        return flag * result;
    }
};
