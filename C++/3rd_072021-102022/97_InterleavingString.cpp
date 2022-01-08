//
// Created by BrandonZu on 1/8/22.
//

#include "common.h"

// Runtime 4ms(>72%) | Memory Usage 6.6MB(>61%)
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size(), m = s2.size(), o = s3.size();
        if(n + m != o)
            return false;

        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
        dp[0][0] = true;
        for(int i = 1; i <= n && s1[i - 1] == s3[i - 1]; i++) {
            dp[i][0] = true;
        }
        for(int j = 1; j <= m && s2[j - 1] == s3[j - 1]; j++) {
            dp[0][j] = true;
        }

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(s1[i - 1] == s3[i + j - 1])
                    dp[i][j] = dp[i][j] || dp[i - 1][j];
                if(s2[j - 1] == s3[i + j - 1])
                    dp[i][j] = dp[i][j] || dp[i][j - 1];
            }
        }
        return dp[n][m];
    }
};
