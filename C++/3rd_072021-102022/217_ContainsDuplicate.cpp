//
// Created by BrandonZu on 11/5/21.
//

#include "common.h"

// Runtime 36ms(>58%) | Memory Usage 20MB(61%)
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> num_map;
        for(int num: nums) {
            num_map[num]++;
            if(num_map[num] > 1)
                return true;
        }
        return false;
    }
};

