//
// Created by BrandonZu on 10/1/21.
//

#include "common.h"

// DP
// if(p == '*') dp[i][j] = dp[i][j - 2] || dp[i - 1][j - 2] && s[i] == p[j - 2] || ...
// if(p == '.') dp[i][j] = dp[i - 1][j - 1]
// if(p != '.' && p != '*') dp[i][j] = dp[i - 1][j - 1] && s[i] == p[j]

// Runtime 4ms(>83%) | Memory Usage 7MB(>45%)
class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<bool>> dp(s.size() + 1, vector<bool>(p.size() + 1, false));
        // Base Case
        dp[0][0] = true;
        for(int j = 2; j <= p.size(); j++) {
            if(p[j - 1] == '*')
                dp[0][j] = dp[0][j - 2];
        }
        // DP
        for(int i = 1; i <= s.size(); i++) {
            for(int j = 1; j <= p.size(); j++) {
                if(p[j - 1] == '*') {
                    char c = p[j - 2];
                    dp[i][j] = dp[i][j - 2] || dp[i - 1][j] && (c == '.' || s[i - 1] == c);
                }
                else {
                    dp[i][j] = dp[i - 1][j - 1] && (p[j - 1] == '.' || s[i - 1] == p[j - 1]);
                }
            }
        }
        return dp[s.size()][j.size()];
    }
};
