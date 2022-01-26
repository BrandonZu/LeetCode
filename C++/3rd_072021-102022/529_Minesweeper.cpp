//
// Created by BrandonZu on 1/26/22.
//

#include "common.h"

// Runtime 33ms(>37%) | Memory Usage 12.5MB(>45%)
class Solution {
public:
    struct pairHasher {
        int operator() (const pair<int, int>& p) const {
            return p.first * 100 + p.second;
        }
    };

    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int n = board.size(), m = board[0].size();
        const int dx[8] = {0, 1, 0, -1, 1, 1, -1, -1}, dy[9] = {1, 0, -1, 0, 1, -1, 1, -1};
        vector<vector<int>> mine_cnt(n, vector<int>(m, 0));

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(board[i][j] == 'M') {
                    for(int d = 0; d < 8; d++) {
                        int x = i + dx[d], y = j + dy[d];
                        if(x >= 0 && x < n && y >= 0 && y < m) {
                            mine_cnt[x][y]++;
                        }
                    }
                }
            }
        }

        if(board[click[0]][click[1]] == 'M') {
            board[click[0]][click[1]] = 'X';
            return board;
        }

        queue<pair<int, int>> q;
        unordered_set<pair<int, int>, pairHasher> visited;
        q.push({click[0], click[1]});
        visited.insert({click[0], click[1]});
        while(!q.empty()) {
            auto p = q.front();
            q.pop();
            if(mine_cnt[p.first][p.second] > 0) {
                board[p.first][p.second] = '0' + mine_cnt[p.first][p.second];
            }
            else {
                board[p.first][p.second] = 'B';
                for(int d = 0; d < 8; d++) {
                    int x = p.first + dx[d], y = p.second + dy[d];
                    if(x >= 0 && x < n && y >= 0 && y < m && visited.find({x, y}) == visited.end()) {
                        visited.insert({x, y});
                        q.push({x, y});
                    }
                }
            }
        }
        return board;
    }
};

