//
// Created by BrandonZu on 9/25/21.
//

#include "common.h"

// Runtime 24ms(>36%) | Memory Usage 13.3MB(>14%)
class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        map<int, int> TreeMap;
        for(auto& tmp: intervals) {
            TreeMap[tmp[0]]++;
            TreeMap[tmp[1]]--;
        }
        int cnt = 0;
        for(auto& p: TreeMap) {
            cnt += p.second;
            if(cnt > 1)
                return false;
        }
        return true;
    }
};

// R .17 | M .46
class Solution2 {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        for(int i = 1; i < intervals.size(); i++) {
            if(intervals[i - 1][1] > intervals[i][0]) {
                return false;
            }
        }
        return true;
    }
};