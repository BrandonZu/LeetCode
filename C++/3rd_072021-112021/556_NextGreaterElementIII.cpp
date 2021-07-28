//
// Created by BrandonZu on 2021/7/26.
//

#include "common.h"

// Runtime 0ms(>100%) | Memory Usage MB(>66%)
class Solution {
public:
    int nextGreaterElement(int n) {
        vector<int> digits;
        int tmp = n;
        while(tmp) {
            digits.push_back(tmp % 10);
            tmp /= 10;
        }
        reverse(digits.begin(), digits.end());

        int pos = digits.size() - 1;
        while(pos > 0 && digits[pos] <= digits[pos - 1])
            pos--;
        if(pos == 0)
            return -1;
        int cur = pos - 1;
        while(pos < digits.size() && digits[pos] > digits[cur])
            pos++;

        swap(digits[cur], digits[pos - 1]);
        reverse(digits.begin() + cur + 1, digits.end());

        long long res = 0;
        for(int x: digits) {
            res *= 10;
            res += x;
            if(res > INT_MAX)
                return -1;
        }

        return res;
    }
};
