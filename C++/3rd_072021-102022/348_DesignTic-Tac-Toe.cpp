//
// Created by BrandonZu on 11/27/21.
//

#include "common.h"

// Runtime 20ms(>94%) | Memory Usage 19.4MB(>41%)
class TicTacToe {
    vector<int> rows, cols;
    int diagonal, antiDiagonal;
    int n;
public:
    TicTacToe(int n) {
        this->n = n;
        rows.resize(n, 0);
        cols.resize(n, 0);
        diagonal = antiDiagonal = 0;
    }

    int move(int row, int col, int player) {
        int toAdd = player == 1 ? 1 : -1;
        rows[row] += toAdd;
        cols[col] += toAdd;
        if(row == col) {
            diagonal += toAdd;
        }
        if(row + col == n - 1) {
            antiDiagonal += toAdd;
        }
        if(rows[row] == n || cols[col] == n || diagonal == n || antiDiagonal == n) {
            return 1;
        }
        if(rows[row] == -n || cols[col] == -n || diagonal == -n || antiDiagonal == -n) {
            return 2;
        }
        return 0;
    }
};
