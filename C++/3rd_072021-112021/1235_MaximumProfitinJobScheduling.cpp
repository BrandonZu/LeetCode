//
// Created by BrandonZu on 11/2/21.
//

#include "common.h"

// Runtime 224ms(>36%) | Memory Usage 64MB(>33%)
class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<vector<int>> jobs(n);
        for(int i = 0; i < n; i++) {
            jobs[i] = {endTime[i], startTime[i], profit[i]};
        }
        sort(jobs.begin(), jobs.end());
        map<int, int> dp = {{0, 0}};
        for(auto& job: jobs) {
            dp[job[0]] = dp.rbegin()->second;
            int cur_val = prev(dp.upper_bound(job[1]))->second + job[2];
            dp[job[0]] = max(dp[job[0]], cur_val);
        }
        return dp.rbegin()->second;
    }
};
