//
// Created by BrandonZu on 11/26/21.
//

#include "common.h"

// Runtime 11ms(>80%) | Memory Usage 7.9MB(>52%)
class Solution {
    const int kRest = 26;
public:
    inline int d(int a, int b) {
        if(a == kRest || b == kRest)
            return 0;
        else
            return abs(a / 6 - b / 6) + abs(a % 6 - b % 6);
    }

    int minimumDistance(string word) {
        int n = word.size();
        vector<vector<int>> dp(n + 1, vector<int>(27, 1e8));
        dp[0][kRest] = 0;

        for(int i = 0; i < n; i++) {
            int prev = i == 0 ? kRest : word[i - 1] - 'A';
            int c = word[i] - 'A';
            for(int j = 0; j <= 26; j++) {
                dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + d(prev, c));
                dp[i + 1][prev] = min(dp[i + 1][prev], dp[i][j] + d(j, c));
            }
        }

        return *min_element(begin(dp[n]), end(dp[n]));
    }
};

// Runtime 68ms(>41%) | Memory Usage 46MB(>26%)
class Solution_Naive {
    const int kRest = 26;
    int n;
public:
    inline int d(int a, int b) {
        if(a == kRest || b == kRest)
            return 0;
        else
            return abs(a / 6 - b / 6) + abs(a % 6 - b % 6);
    }

    int recur(vector<vector<vector<int>>>& mem, string& word, int i, int l, int r) {
        if(i == n) return 0;
        if(mem[i][l][r]) return mem[i][l][r];
        int c = word[i] - 'A';
        if(l != r)
            return mem[i][l][r] = min(recur(mem, word, i + 1, c, r) + d(l, c), recur(mem, word, i + 1, l, c) + d(c, r));
        else
            return mem[i][l][r] = recur(mem, word, i + 1, c, r) + d(l, c);
    }

    int minimumDistance(string word) {
        n = word.length();
        vector<vector<vector<int>>> mem(n, vector<vector<int>>(27, vector<int>(27)));
        return recur(mem, word, 0, kRest, kRest);
    }
};

