//
// Created by BrandonZu on 2021/8/8.
//

#include "common.h"

// Runtime 12ms(>60%) | Memory Usage 9MB(>30%)
class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1, 0));
        for(int j = 1; j <= word2.size(); j++)
            dp[0][j] = j;
        for(int i = 1; i <= word1.size(); i++)
            dp[i][0] = i;

        for(int i = 1; i <= word1.size(); i++) {
            for(int j = 1; j <= word2.size(); j++) {
                if(word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else {
                    dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
                }
            }
        }

        return dp[word1.size()][word2.size()];
    }
};

// Runtime 8ms(>82%)| Memory Usage 6.3MB(>97%)
class Solution_Optimized {
public:
    int minDistance(string word1, string word2) {
        vector<int> dp(word2.size() + 1, 0);
        for(int j = 1; j <= word2.size(); j++)
            dp[j] = j;

        int cur, pre;
        for(int i = 1; i <= word1.size(); i++) {
            pre = dp[0];
            dp[0] = i;
            for(int j = 1; j <= word2.size(); j++) {
                cur = dp[j];
                if(word1[i - 1] == word2[j - 1]) {
                    dp[j] = pre;
                }
                else {
                    dp[j] = min(min(dp[j], dp[j - 1]), pre) + 1;
                }
                pre = cur;
            }
        }

        return dp[word2.size()];
    }
};