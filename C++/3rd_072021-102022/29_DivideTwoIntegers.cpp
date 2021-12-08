//
// Created by BrandonZu on 12/7/21.
//

#include "common.h"

// Runtime 5ms(>12.14%) | Memory Usage 6.2MB(>6.5%)
class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }
        int flag = dividend > 0 ^ divisor > 0 ? -1 : 1;
        long x = labs(dividend), y = labs(divisor);
        long res = 0;
        vector<long> exp;
        for(long i = y; i <= x; i <<= 1)
            exp.push_back(i);

        for(int i = exp.size() - 1; i >= 0; i--) {
            if(x >= exp[i]) {
                x -= exp[i];
                res += 1L << i;
            }
        }
        return res * flag;
    }
};
