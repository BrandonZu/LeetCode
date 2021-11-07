//
// Created by BrandonZu on 10/16/21.
//

#include "common.h"

// Runtime 8ms(>93%) | Memory Usage 6.5MB(>32%)
class Solution {
public:
    int countArrangement(int n) {
        vector<int> dp(1 << n);
        dp[0] = 1;
        for(int i = 0; i < 1 << n; i++) {
            int k = 0;
            for(int j = 0; j < n; j ++) {
                if(i >> j & 1)
                    k++;
            }
            for(int j = 0; j < n; j++) {
                if((i >> j & 1) == 0) {
                    if((j + 1) % (k + 1) == 0 || (k + 1) % (j + 1) == 0)
                        dp[i | (1 << j)] += dp[i];
                }
            }
        }
        return dp[(1 << n) - 1];
    }
};
