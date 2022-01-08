//
// Created by BrandonZu on 2021/8/10.
//

#include "common.h"

// Runtime 0ms(100%) | Memory Usage 6MB(>40%)
class Solution {
public:
    double myPow(double x, int n) {
        double res = 1;
        // Notice: abs(INT_MIN) exceeds the scope of int
        long p = abs(n);
        while(p) {
            if(p & 1) {
                res *= x;
            }
            p = p >> 1;
            x *= x;
        }

        return n >= 0 ? res : 1.0/res;
    }
};

// 1st Review 12/12/21
// Runtime 0ms(100%) | Memory Usage 6MB(>42%)
class Solution_R1 {
public:
    double myPow(double x, int n) {
        double res = 1;
        long abs_n = abs(n);
        while(abs_n) {
            if(abs_n & 1) {
                res *= x;
            }
            abs_n >>= 1;
            x *= x;
        }
        return n >= 0 ? res : 1 / res;
    }
};