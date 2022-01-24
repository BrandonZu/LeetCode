//
// Created by BrandonZu on 1/23/22.
//

#include "common.h"

// Runtime 4ms(>78%) | Memory Usage 6MB(>25%)
class Solution {
public:
    // a + a+1 + a+2 + ... + a+b-1 == n -> (a + a+b-1)b/2 == n -> 2a = 2n/b - (b - 1)
    // b * b <= 2n
    int consecutiveNumbersSum(int n) {
        n *= 2;
        int cnt = 0;
        for(int b = 1; b * b <= n; b++) {
            if(n % b == 0 && (n / b - (b - 1)) % 2 == 0)
                cnt++;
        }
        return cnt;
    }
};

// TLE
class Solution_TLE {
public:
    int getSum(int l, int r) {
        return (l + r) * (r - l + 1) / 2;
    }

    int consecutiveNumbersSum(int n) {
        int l = 1, r = 1;
        int cnt = 1;
        while(r < (n + 1) / 2) {
            r++;
            while(r < (n + 1) / 2 && getSum(l, r) < n) {
                r++;
            }

            while(l < r && getSum(l, r) > n) {
                l++;
            }

            if(getSum(l, r) == n)
                cnt++;
        }
        return cnt;
    }
};
