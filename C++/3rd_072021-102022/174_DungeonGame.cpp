//
// Created by BrandonZu on 11/24/21.
//

#include "common.h"

// Runtime 15ms(>15%) | Memory Usage 9MB(>50%)
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n = dungeon.size(), m = dungeon[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 1e8));
        dp[n - 1][m - 1] = max(1, 1 - dungeon[n - 1][m - 1]);
        for(int i = n - 1; i >= 0; i--) {
            for(int j = m - 1; j >= 0; j--) {
                if(i == n - 1 && j == m - 1)
                    continue;
                else {
                    if(i + 1 < n)
                        dp[i][j] = min(dp[i][j], dp[i + 1][j]);
                    if(j + 1 < m)
                        dp[i][j] = min(dp[i][j], dp[i][j + 1]);
                    dp[i][j] = max(1, dp[i][j] - dungeon[i][j]);
                }
            }
        }
        return dp[0][0];
    }
};


struct PairHasher {
    int operator()(const pair<int, int> &V) const {
        long hash = 2;
        hash ^= V.first + 0x9e3779b9 + (hash << 6) + (hash >> 2);
        hash ^= V.second + 0x9e3779b9 + (hash << 6) + (hash >> 2);
        return (int)hash;
    }
};

// Runtime 20ms(>9%) | Memory Usage 12.7MB(>5.2%)
class Solution_TopDown {
public:
    unordered_map<pair<int, int>, int, PairHasher> memo;
    int n, m;
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        n = dungeon.size(), m = dungeon[0].size();
        memo[{n - 1, m - 1}] = max(1, 1 - dungeon[n - 1][m - 1]);
        return recur(dungeon, 0, 0);
    }

    int recur(vector<vector<int>>& dungeon, int i, int j) {
        if(memo.find({i, j}) != memo.end()) {
            return memo[{i, j}];
        }
        int ret = INT_MAX;
        if(i + 1 < n) {
            ret = min(ret, recur(dungeon, i + 1, j));
        }
        if(j + 1 < m) {
            ret = min(ret, recur(dungeon, i, j + 1));
        }
        memo[{i, j}] = max(1, ret - dungeon[i][j]);
        return memo[{i, j}];
    }
};
