//
// Created by BrandonZu on 2021/8/8.
//

#include "common.h"

// 1st Review 03/30/22

// Runtime ms() | Memory Usage MB()
class Solution_R1_Optimized {
public:
    int longestCommonSubsequence(string text1, string text2) {

    }
};

// Runtime ms() | Memory Usage MB()
class Solution_R1_Trivial {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(), m = text2.size();
        vector<vector<int>> dp(2, vector<int>(m + 1, 0));
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(text1[i - 1] == text2[j - 1]) {
                    dp[i % 2][j] = dp[(i - 1) % 2][j - 1] + 1;
                }
                else {
                    dp[i % 2][j] = max(dp[(i - 1) % 2][j], dp[i % 2][j - 1]);
                }
            }
        }
        return dp[n % 2][m];
    }
};

// 0st 08/
// Runtime 35ms(>15%) | Memory Cost 12.9MB(>44%)
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size() + 1, vector<int>(text2.size() + 1));
        for(int i = 1; i <= text1.size(); i++) {
            for(int j = 1; j <= text2.size(); j++) {
                if(text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
                }
                else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[text1.size()][text2.size()];
    }
};

// Runtime 30ms(>18.6%) | Memory Cost 6.5MB(>94.4%)
class Solution_Optimized1 {
public:
    int longestCommonSubsequence(string text1, string text2) {
        if(text1.size() < text2.size()) return longestCommonSubsequence(text2, text1);
        vector<vector<int>> dp(2, vector<int>(text2.size() + 1));
        for(int i = 1; i <= text1.size(); i++) {
            for(int j = 1; j <= text2.size(); j++) {
                if(text1[i - 1] == text2[j - 1]) {
                    dp[i % 2][j] = max(dp[i % 2][j], dp[(i + 1) % 2][j - 1] + 1);
                }
                else {
                    dp[i % 2][j] = max(dp[(i + 1) % 2][j], dp[i % 2][j - 1]);
                }
            }
        }
        return dp[text1.size() % 2][text2.size()];
    }
};

// Runtime 24ms(>38%) | Memory Usage 6.5MB(98%)
class Solution_Optimized2 {
public:
    int longestCommonSubsequence(string text1, string text2) {
        if(text1.size() < text2.size()) return longestCommonSubsequence(text2, text1);
        vector<int> dp(text2.size() + 1);
        int pre_val = 0, cur_val = 0;
        for(int i = 1; i <= text1.size(); i++) {
            pre_val = 0;
            for(int j = 1; j <= text2.size(); j++) {
                cur_val = dp[j]; // cur_val == dp[i - 1][j]
                if(text1[i - 1] == text2[j - 1]) {
                    dp[j] = max(dp[j], pre_val + 1); // pre_val == dp[i - 1][j - 1]
                }
                else {
                    dp[j] = max(dp[j], dp[j - 1]);
                }
                pre_val = cur_val;
            }
        }
        return dp[text2.size()];
    }
};

