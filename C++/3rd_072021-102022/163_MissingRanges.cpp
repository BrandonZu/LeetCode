//
// Created by BrandonZu on 11/16/21.
//

#include "common.h"

// Runtime 0ms(>100%) | Memory Usage 7MB(>83%)
class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> res;
        int next = lower;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] != next) {
                if(nums[i] == next + 1)
                    res.push_back(to_string(next));
                else {
                    res.push_back(to_string(next) + "->" + to_string(nums[i] - 1));
                }
            }
            next = nums[i] + 1;
        }
        if(next == upper) {
            res.push_back(to_string(upper));
        }
        else if(next < upper) {
            res.push_back(to_string(next) + "->" + to_string(upper));
        }
        return res;
    }
};
