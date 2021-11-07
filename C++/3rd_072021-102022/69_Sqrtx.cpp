//
// Created by BrandonZu on 10/1/21.
//

#include "common.h"

// Runtime 0ms(>100%) | Memory Usage 5.9MB(>75%)
class Solution {
public:
    int mySqrt(int x) {
        long l = 0, r = x;
        while(r - l > 1) {
            long mid = (l + r) / 2;
            if(mid * mid == x) {
                return mid;
            }
            else if(mid * mid > x) {
                r = mid;
            }
            else {
                l = mid;
            }
        }
        if(r * r == x)
            return r;
        else
            return l;
    }
};
