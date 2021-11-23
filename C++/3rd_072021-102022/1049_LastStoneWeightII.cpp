//
// Created by BrandonZu on 11/22/21.
//

#include "common.h"

// Runtime 4ms(>93%) | Memory Usage 7.9MB(>100%)
class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int sum = 0;
        for(int i: stones) sum += i;

        int req = sum / 2;
        vector<bool> dp(req + 1, false);
        dp[0] = true;
        for(int i: stones) {
            for(int j = req; j >= i; j--) {
                if(dp[j - i])
                    dp[j] = true;
            }
        }

        for(int j = req; j >= 0; j--) {
            if(dp[j])
                return (sum - j) - j;
        }
        return 0;
    }
};

