//
// Created by BrandonZu on 1/23/22.
//

#include "common.h"

// Runtime 43ms(>57%) | Memory Usage 28MB(>41%)
class Solution {
public:
    int minMoves(vector<int>& nums) {
        int minNum = INT_MAX;
        for(int n: nums) {
            minNum = min(minNum, n);
        }
        int ans = 0;
        for(int n: nums) {
            ans += n - minNum;
        }
        return ans;
    }
};
