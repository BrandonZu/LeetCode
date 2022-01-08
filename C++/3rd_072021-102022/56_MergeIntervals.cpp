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

// 1st Review 12/12/21
// Runtime 16ms(>89%) | Memory Usage 14.1MB(>95%)
class Solution_R1 {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;
        int i = 0;
        while(i < n) {
            int j;
            int r = intervals[i][1];
            for(j = i + 1; j < n && intervals[j][0] <= r; j++) {
                r = max(r, intervals[j][1]);
            }
            res.push_back({intervals[i][0], r});
            i = j;
        }
        return res;
    }
};

