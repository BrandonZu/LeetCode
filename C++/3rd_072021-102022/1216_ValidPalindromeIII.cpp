//
// Created by BrandonZu on 12/7/21.
//

#include "common.h"

// Runtime 24ms(>56%) | Memory Usage 16.8MB(>19%)
class Solution {
public:
    bool isValidPalindrome(string s, int k) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n));
        for(int i = 0; i < n; i++) {
            dp[i][i] = 1;
        }
        for(int len = 2; len <= n; len++) {
            for(int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;
                if(s[i] == s[j]) {
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                }
                else {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[0][n - 1] + k >= n;
    }
};

