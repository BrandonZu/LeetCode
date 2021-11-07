//
// Created by BrandonZu on 2021/8/2.
//

#include "common.h"

// Runtime 0ms(>100%) | Memory Usage 5.9MB(>78%)
class Solution{
public:
    int fib(int n) {
        if(n == 0) return 0;

        int ll = 0, l = 1;
        int cur = 1;

        for(int i = 2; i <= n; i++) {
            cur = l + ll;
            ll = l;
            l = cur;
        }
        return cur;
    }
};
