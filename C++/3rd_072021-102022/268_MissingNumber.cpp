//
// Created by BrandonZu on 2021/8/18.
//

#include "common.h"

// Runtime 16ms(>82%) | Memory Usage 17.9MB(>92%)
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sum = (1 + n) * n / 2;
        for(int num: nums)
            sum -= num;
        return sum;
    }
};