//
// Created by BrandonZu on 2021/8/15.
//

#include "common.h"

// DP
// s[l] == s[r] -> dp[l][r] = dp[l + 1][r - 1] + 2
// s[l] != s[r] -> dp[l][r] = max(dp[l + 1][r], dp[l][r - 1])

// Runtime 56ms(>85%) | Memory Usage 6.5MB(>99%)
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        vector<int> dp(s.size() + 1, 0);
        int pre = 0;
        for(int l = s.size(); l >= 1; l--) {
            dp[l] = 1;
            pre = 0;
            for(int r = l + 1; r <= s.size(); r++) {
                int origin = dp[r];
                if(s[l - 1] == s[r - 1])
                    dp[r] = pre + 2;
                else
                    dp[r] = max(dp[r], dp[r - 1]);
                pre = origin;
            }
        }

        return dp[s.size()];
    }
};
