//
// Created by BrandonZu on 1/12/22.
//

#include "common.h"

// Runtime 60ms(>85%) | Memory Usage 29MB(>71%)
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(), nums.end());
        int res = 0;
        for(int i: nums) {
            if(numSet.find(i - 1) == numSet.end()) {
                int cur = i;
                while(numSet.find(cur) != numSet.end()) {
                    cur++;
                }
                res = max(res, cur - i);
                numSet.erase(i);
            }
        }
        return res;
    }
};
