//
// Created by BrandonZu on 11/28/21.
//

#include "common.h"

// Runtime 4ms(>70%) | Memory Usage 9.7MB(>55%)
class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int> dp(n + 1, 0);
        int thirty = 0, seven = 0;
        for(int i = 1; i <= n; i++) {
            while(days[i - 1] - days[thirty + 1 - 1] >= 30) thirty++;
            while(days[i - 1] - days[seven + 1 - 1] >= 7) seven++;
            dp[i] = min(min(dp[thirty] + costs[2], dp[seven] + costs[1]), dp[i - 1] + costs[0]);
        }
        return dp[n];
    }
};

