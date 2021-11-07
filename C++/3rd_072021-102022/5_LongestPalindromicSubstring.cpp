//
// Created by BrandonZu on 9/28/21.
//

#include "common.h"

// Runtime 363ms(>26%) | Memory Usage 31MB(>38%)
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        int maxLen = 1;
        int maxStart = 0;

        for(int i = n - 1; i >= 0; i--) {
            for(int j = i; j < n; j++) {
                if(s[i] == s[j]) {
                    if(j - i <= 1)
                        dp[i][j] = true;
                    else if(dp[i + 1][j - 1])
                        dp[i][j] = true;
                }
                if(dp[i][j] && j - i + 1 > maxLen) {
                    maxStart = i;
                    maxLen = j - i + 1;
                }
            }
        }
        return s.substr(maxStart, maxLen);
    }
};

