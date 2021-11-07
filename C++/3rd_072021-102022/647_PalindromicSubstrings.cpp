//
// Created by BrandonZu on 2021/8/15.
//

#include "common.h"

// DP
// s[l] == s[r] -> dp[i][j] = dp[i + 1][j - 1]
// s[l] != s[r] -> dp[i][j] = false

// Runtime 4ms(>91%) | Memory Usage 6.4MB(>78%)
class Solution_DP {
public:
    int countSubstrings(string s) {
        vector<bool> dp(s.size() + 1, false);
        int res = 0;
        for(int l = s.size(); l >= 1; l--) {
            for(int r = s.size(); r >= l; r--) {
                if(s[l - 1] == s[r - 1]) {
                    if(r - l <= 1 || dp[r - 1]) {
                        dp[r] = true;
                        res++;
                    }
                    else
                        dp[r] = false;
                }
                else {
                    dp[r] = false;
                }
            }
        }
        return res;
    }
};

class Solution_DP_2 {
public:
    int countSubstrings(string s) {
        // When l == r(one char) or r < l(empty string), dp[l][r] = true
        vector<bool> dp(s.size() + 1, true);
        int res = 0;
        for(int l = s.size(); l >= 1; l--) {
            for(int r = s.size(); r >= l; r--) {
                if(s[l - 1] == s[r - 1]) {
                    if(dp[r - 1]) {
                        dp[r] = true;
                        res++;
                    }
                    else
                        dp[r] = false;
                }
                else {
                    dp[r] = false;
                }
            }
        }
        return res;
    }
};

// 1st Review 10/19/21
// Runtime ms() | Memory Cost MB()
class Solution_R1 {
public:
    int countSubstrings(string s) {
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));
        for(int i = s.size(); i >= 1; i++) {
            for(int j = )
        }
    }
};