//
// Created by BrandonZu on 11/6/21.
//

#include "common.h"

// Runtime 20ms(>66%) | Memory Usage 17MB(>50%)
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        for(int num: nums) {
            result ^= num;
        }
        return result;
    }
};


// Runtime 32ms(>28%) | Memory Usage 20MB(>11%)
class Solution_HashMap {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> num_map;
        for(int num: nums) {
            num_map[num]++;
        }
        for(auto& [k, v]: num_map) {
            if(v == 1) {
                return k;
            }
        }
        return -1;
    }
};
