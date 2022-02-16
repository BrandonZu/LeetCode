//
// Created by BrandonZu on 2/16/22.
//

#include "common.h"

// Runtime 0ms(>100%) | Memory Usage 6.7MB(>100%)
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n = nums.size();
        vector<string> res;
        if(nums.empty()) return res;
        int pos = 0;
        while(pos < n) {
            int cur = nums[pos];
            pos++;
            while(pos < n && nums[pos] == nums[pos - 1] + 1) {
                pos++;
            }
            if(nums[pos - 1] == cur) {
                res.push_back(to_string(cur));
            }
            else {
                res.push_back(to_string(cur) + "->" + to_string(nums[pos - 1]));
            }
        }
        return res;
    }
};
