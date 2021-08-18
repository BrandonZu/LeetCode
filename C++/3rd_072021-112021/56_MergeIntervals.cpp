//
// Created by BrandonZu on 2021/8/17.
//

#include "common.h"

// Runtime 12ms(>99%) | Memory usage 14.8MB(>32%)
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;
        for(auto i : intervals) {
            if(res.empty() || res.back()[1] < i[0]) {
                res.push_back(i);
            }
            else {
                res.back()[1] = max(res.back()[1], i[1]);
            }
        }
        return res;
    }
};

