//
// Created by BrandonZu on 2021/8/15.
//

#include "common.h"

// DP
// t[i] == s[j] -> dp[i][j] = dp[i - 1][j - 1]
// t[i] != s[j] -> dp[i][j] = dp[i - 1][j]
// Runtime 0ms(>100%) | Memory Usage 6.5MB(>35%)
class Solution_DP {
public:
    bool isSubsequence(string s, string t) {
        vector<bool> dp(s.size() + 1);
        dp[0] = true;
        for(int i = 1; i <= t.size(); i++) {
            for(int j = s.size(); j >= 1; j--) {
                if(t[i - 1] == s[j - 1])
                    dp[j] = dp[j - 1];
            }
        }
        return dp[s.size()];
    }
};

// Runtime 0ms(>100%) | Memory Usage 6.3MB(>70%)
class Solution_Pointers {
public:
    bool isSubsequence(string s, string t) {
        int s_pos = 0, t_pos = 0;
        while(s_pos < s.size() && t_pos < t.size()) {
            if(s[s_pos] == t[t_pos]) {
                ++s_pos;
            }
            ++t_pos;
        }
        return s_pos >= s.size();
    }
};
