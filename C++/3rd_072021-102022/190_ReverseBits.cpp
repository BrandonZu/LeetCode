//
// Created by BrandonZu on 2/19/22.
//

#include "common.h"

// Runtime 4ms(>47%) | Memory Usage 6MB(>52%)
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ret = 0;
        for(int i = 0; i < 32; i++, n >>= 1) {
            ret <<= 1;
            if(n & 1) {
                ret |= 1;
            }
        }
        return ret;
    }
};
