//
// Created by BrandonZu on 1/18/22.
//

#include "common.h"

// Runtime 9ms(>52%) | Memory Usage 9.5MB(>56%)
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int one = 0, two = 0;
        for(int x: nums) {
            one = (one ^ x) & ~two;
            two = (two ^ x) & ~one;
        }
        return one;
    }
};
