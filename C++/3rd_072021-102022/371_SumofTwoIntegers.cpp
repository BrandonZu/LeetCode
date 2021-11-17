//
// Created by BrandonZu on 11/16/21.
//

#include "common.h"

// Runtime 0ms(>100%) | Memory Usage 5.8MB(>96%)
class Solution {
public:
    int getSum(int a, int b) {
        unsigned carry;
        while(a) {
            carry = a & b;
            b = a ^ b;
            a = carry << 1;
        }
        return b;
    }
};
