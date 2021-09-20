//
// Created by BrandonZu on 2021/8/15.
//

#include "common.h"

// DP
// s[i] == t[j] -> dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j]
// s[i] != t[j] -> dp[i][j] = dp[i - 1][j]

// Runtime 12ms(>76%) | Memory Usage 6.4MB(>96%)
class Solution {
public:
    int numDistinct(string s, string t) {
        vector<double> dp(t.size() + 1);
        dp[0] = 1;
        for(int i = 1; i <= s.size(); i++) {
            for(int j = t.size(); j >= 1; j--) {
                if(s[i - 1] == t[j - 1])
                    dp[j] = dp[j] + dp[j - 1];
            }
        }
        return dp[t.size()];
    }
};

