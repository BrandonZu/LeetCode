//
// Created by BrandonZu on 11/6/21.
//

#include "common.h"

// Runtime 8ms(>99%) | Memory Usage 17MB(>77%)
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> result;
        int pos = 0;
        while(pos < intervals.size() && intervals[pos][1] < newInterval[0]) {
            result.push_back(intervals[pos]);
            pos++;
        }
        if(pos < intervals.size()) {
            newInterval[0] = min(newInterval[0], intervals[pos][0]);
            while(pos < intervals.size() && intervals[pos][0] <= newInterval[1]) {
                newInterval[1] = max(newInterval[1], intervals[pos][1]);
                pos++;
            }
        }
        result.push_back(newInterval);
        while(pos < intervals.size()) {
            result.push_back(intervals[pos]);
            pos++;
        }
        return result;
    }
};

// R .29 | M .37
class Solution2 {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        int i = 0;
        while (i < intervals.size() && intervals[i][1] < newInterval[0]) {
            res.push_back(intervals[i++]);
        }

        if (i < intervals.size()) {
            newInterval[0] = min(intervals[i][0], newInterval[0]);
            while (i < intervals.size() && intervals[i][0] <= newInterval[1]) {
                newInterval[1] = max(newInterval[1], intervals[i][1]);
                i++;
            }
        }
        res.push_back(newInterval);

        while(i < intervals.size()) {
            res.push_back(intervals[i++]);
        }

        return res;
    }
};