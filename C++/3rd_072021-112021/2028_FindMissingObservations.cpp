//
// Created by BrandonZu on 10/3/21.
//

#include "common.h"

// Runtime 148ms(>94%) | Memory Usage 113.8MB(>94%)
class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int total = mean * (rolls.size() + n);
        for(int r : rolls)
            total -= r;
        if(total < n || total > 6*n) return {};

        int mod = total % n;
        vector<int> res(n, total / n);
        for(int i = 0; i < mod; i++)
            res[i]++;
        return res;
    }
};
