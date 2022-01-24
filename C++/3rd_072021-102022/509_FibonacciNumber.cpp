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

// 1st Review 1/23/22
// Runtime 0ms(>100%) | Memory Usage 5.9MB(>29%)
class Solution_R1 {
public:
    int fib(int n) {
        if(n == 0) return 0;
        int num_0 = 0, num_1 = 1;
        for(int i = 1; i < n; i++) {
            int tmp = num_1;
            num_1 = num_0 + num_1;
            num_0 = tmp;
        }
        return num_1;
    }
};