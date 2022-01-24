//
// Created by BrandonZu on 1/23/22.
//

#include "common.h"

// Runtime 0ms(>100%) | Memory Usage 6MB(>50%)
class Solution {
public:
    int tribonacci(int n) {
        if(n == 0) return 0;
        if(n == 1) return 1;
        int num_0 = 0, num_1 = 1, num_2 = 1;
        for(int i = 2; i < n; i++) {
            int tmp = num_2;
            num_2 += num_0 + num_1;
            num_0 = num_1;
            num_1 = tmp;
        }
        return num_2;
    }
};
