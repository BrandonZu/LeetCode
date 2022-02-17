//
// Created by BrandonZu on 2/17/22.
//

#include "common.h"

// Runtime 0ms(>100%) | Memory Usage 5.9MB(>23%)
class Solution_BEST {
public:
    bool isPowerOfTwo(int n) {
        return n > 0 && (n & (n - 1)) == 0;
    }
};

// Runtime 4ms(>35%) | Memory Usage 6MB(>23%)
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n < 1) return false;
        bool found = false;
        while(n) {
            if(n & 1 && found) {
                return false;
            }
            else if(n & 1) {
                found = true;
            }
            n >>= 1;
        }
        return found;
    }
};
