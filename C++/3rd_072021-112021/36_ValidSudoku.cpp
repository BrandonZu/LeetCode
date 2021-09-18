//
// Created by BrandonZu on 2021/8/29.
//

#include "common.h"

// Runtime 16ms(>92%) | Memory Usage 19.MB(>40%)
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<bool>> grid(9, vector<bool>(9, false));
        vector<vector<bool>> row(9, vector<bool>(9, false));
        vector<vector<bool>> col(9, vector<bool>(9, false));
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                if(board[i][j] >= '0' && board[i][j] <= '9') {
                    int num = board[i][j] - '0' - 1;
                    int gridPos = i / 3 * 3 + j / 3;
                    if(row[i][num] || col[j][num] || grid[gridPos][num])
                        return false;
                    row[i][num] = true;
                    col[j][num] = true;
                    grid[gridPos][num] = true;
                }
            }
        }
        return true;
    }
};
