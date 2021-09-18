//
// Created by BrandonZu on 2021/8/24.
//

#include "common.h"

// dp[i][j] 表示 s[i ... j] 中未被匹配的 ( 数量
// dp[i][j] == 0 -> valid parentheses
class Solution {
public:
    int longestValidParentheses(string s) {
        int maxLen = 0;
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), -1));
        for(int i = 0; i < s.size(); i++) {
            dp[i][i] = s[i] == '(' ? 1 : -1;
        }
        for(int len = 2; len <= s.size(); len++) {
            for(int l = 0; l + len - 1 < s.size(); l++) {
                int r = l + len - 1;
                if(dp[l][r - 1] == -1) {
                    if(s[r] == '(')
                        dp[l][r] = 1;
                    else
                        dp[l][r] = -1;
                }
                else {
                    if(s[r] == '(')
                        dp[l][r] = dp[l][r - 1] + 1;
                    else
                        dp[l][r] = dp[l][r - 1] - 1;
                }
                if(dp[l][r] == 0)
                    maxLen = max(maxLen, r - l + 1);
            }
        }
        return maxLen;
    }
};
