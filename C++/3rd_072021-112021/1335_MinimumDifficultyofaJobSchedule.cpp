//
// Created by BrandonZu on 10/24/21.
//

#include "common.h"


// DP[i][k] =
class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        if(jobDifficulty.size() < d) return -1;
        int n = jobDifficulty.size();
        vector<vector<int>> dp(n, vector<int>(d, 0));
        
    }
};

