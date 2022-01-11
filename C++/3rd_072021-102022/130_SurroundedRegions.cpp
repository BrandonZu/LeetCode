//
// Created by BrandonZu on 1/10/22.
//

#include "common.h"

// Runtime 14ms(>46%) | Memory Usage 10.1MB(>43%)
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size(), m = board[0].size();
        const int dir_x[4] = {1, 0, -1, 0}, dir_y[4] = {0, 1, 0, -1};
        if(m == 1 || n == 1)
            return;
        queue<pair<int, int>> q;
        for(int j = 0; j < m; j++) {
            if(board[0][j] == 'O') {
                q.push({0, j});
                board[0][j] = 'S';
            }
            if(board[n - 1][j] == 'O') {
                q.push({n - 1, j});
                board[n - 1][j] = 'S';
            }
        }
        for(int i = 1; i < n - 1; i++) {
            if(board[i][0] == 'O') {
                q.push({i, 0});
                board[i][0] = 'S';
            }
            if(board[i][m - 1] == 'O') {
                q.push({i, m - 1});
                board[i][m - 1] = 'S';
            }
        }

        while(!q.empty()) {
            auto cur = q.front();
            q.pop();
            for(int i = 0; i < 4; i++) {
                int x = cur.first + dir_x[i], y = cur.second + dir_y[i];
                if(x >= 0 && x < n && y >= 0 && y < m && board[x][y] == 'O') {
                    board[x][y] = 'S';
                    q.push({x, y});
                }
            }
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
                else if(board[i][j] == 'S') {
                    board[i][j] = 'O';
                }
            }
        }
    }
};
