//
// Created by BrandonZu on 2021/8/22.
//

#include "common.h"

// Runtime 371ms(>49%) | Memory Usage 7.4MB(>27%)
class Solution {
    int x_dir[4] = {0, 0, 1, -1};
    int y_dir[4] = {1, -1, 0, 0};
public:
    bool dfs(vector<vector<char>>& board, string& word, int x, int y, int s_pos) {
        if(board[x][y] != word[s_pos])
            return false;
        if(s_pos == word.size() - 1)
            return true;

        int tmp = board[x][y];
        board[x][y] = '*';
        for(int i = 0; i < 4; i++) {
            x += x_dir[i], y += y_dir[i];
            if(x >= 0 && x < board.size() && y >= 0 && y < board[0].size()) {
                if(dfs(board, word, x, y, s_pos + 1))
                    return true;
            }
            x-= x_dir[i], y -= y_dir[i];
        }
        board[x][y] = tmp;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[0].size(); j++) {
                if(dfs(board, word, i, j, 0))
                    return true;
            }
        }
        return false;
    }
};
