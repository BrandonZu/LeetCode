//
// Created by BrandonZu on 10/22/21.
//

#include "common.h"

// Runtime 4ms(>89%) | Memory Usage 7.8MB(>73%)
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res(n + 1, 0);
        for(int i = 1; i <= n; i++) {
            res[i] = res[i >> 1] + (i & 1);
        }
        return res;
    }
};
