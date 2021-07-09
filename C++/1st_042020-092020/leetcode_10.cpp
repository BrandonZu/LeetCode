#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        if(p.empty())
            return s.empty();
        vector<vector<bool>> dp(s.length() + 1, vector<bool>(p.length() + 1, false));
        // Innit
        dp[0][0] = true;
        dp[0][1] = false;
        for(int j = 2; j < p.length() + 1; j++) {
            if(p[j] == '*')
                dp[0][j] = dp[0][j-2];
        }

        for(int i = 1; i < s.length() + 1; i++) {
            int s_pos = i - 1;
            for(int j = 1; j < p.length() + 1; j++) {
                int p_pos = j - 1;
                if(s[s_pos] == p[p_pos] || p[p_pos] == '.')
                    dp[i][j] = dp[i-1][j-1];
                else if(s[s_pos] == '*') {
                    if(p[p_pos-1] == s[s_pos] || p[p_pos] == '.')
                        dp[i][j] = dp[i-1][j] || dp[i][j-2];
                    else
                        dp[i][j] = dp[i][j-2];
                }
            }
        }

        return dp[s.length()][p.length()];
    }
};