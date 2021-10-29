//
// Created by BrandonZu on 10/27/21.
//

#include "common.h"

// Runtime 0ms(>100%) | Memory Usage 6MB(>48%)
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res = 0;
        while(n) {
            res += n & 1;
            n >>= 1;
        }
        return res;
    }
};
