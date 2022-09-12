//
// Created by BrandonZu on 11/24/21.
//

#include "common.h"

// Runtime 84ms(>34%) | Memory Usage 9.5MB(>67%)
class Solution {
    // dp[i][j] = dp[i - 1][j] || dp[i - 1][j - 1] || dp[i - 1][j - 2] ... || d[i - 1][0]
    // dp[i][j - 1] = dp[i - 1][j - 1] || dp[i - 1][j - 2] ... || d[i - 1][0]
    // dp[i][j] = dp[i - 1][j] || dp[i][j - 1]
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
        dp[0][0] = true;
        for(int i = 1; i <= n && p[i - 1] == '*'; i++) {
            dp[i][0] = true;
        }

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(p[i - 1] == '*') {
                    dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
                }
                else {
                    dp[i][j] = (p[i - 1] == '?' || p[i - 1] == s[j - 1]) && dp[i - 1][j - 1];
                }
            }
        }
        return dp[n][m];
    }
};

// Runtime 62ms(>50%) | Memory Usage 9.6MB(>65%)
class Solution_2 {
public:
    bool isMatch(string s, string p) {
        int s_len = s.size(), p_len = p.size();
        vector<vector<bool>> dp(p_len + 1, vector<bool>(s_len + 1, false));
        dp[0][0] = true;
        for(int i = 1; i <= p_len; i++) {
            if(p[i - 1] == '?') {
                for(int j = 1; j <= s_len; j++) {
                    dp[i][j] = dp[i - 1][j - 1];
                }
            }
            else if(p[i - 1] == '*') {
                int j = 1;
                while(j <= s_len && !dp[i - 1][j - 1])
                    j++;
                dp[i][j - 1] = dp[i - 1][j - 1];
                while(j <= s_len)
                    dp[i][j++] = true;
            }
            else {
                for(int j = 1; j <= s_len; j++) {
                    if(p[i - 1] == s[j - 1] && dp[i - 1][j - 1])
                        dp[i][j] = true;
                    else
                        dp[i][j] = false;
                }
            }
        }
        return dp[p_len][s_len];
    }
};

// R .42 | M .60
class Solution3 {
public:
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
        dp[0][0] = true;
        for(int j = 1; j <= m && p[j - 1] == '*'; j++) {
            dp[0][j] = true;
        }
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(p[j - 1] == '*') {
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
                }
                else {
                    dp[i][j] = dp[i - 1][j - 1] && (p[j - 1] == '?' || s[i - 1] == p[j - 1]);
                }
            }
        }
        return dp[n][m];
    }
};