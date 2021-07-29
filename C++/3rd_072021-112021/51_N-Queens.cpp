//
// Created by BrandonZu on 2021/7/16.
//

#include "common.h"
using namespace std;

// Runtime 8ms(>50%) | Memory Usage 7.4MB(>56%)
class Solution_1 {
    vector<int> rows;
    vector<vector<int>> results;
public:
    void dfs(int row, int n) {
        if(row == n) {
            results.push_back(rows);
            return;
        }
        for(int i = 0; i < n; i++) {
            if(check(row, i, n)) {
                rows[row] = i;
                dfs(row + 1, n);
                rows[row] = -1;
            }
        }
    }

    bool check(int row, int col, int n) {
        for(int i = 0; i < row; i++) {
            if((col - (i - row) >= 0 && rows[i] == col - (i - row)) || rows[i] == col || (col + (i - row) < n && rows[i] == col + (i - row)))
                return false;
        }
        return true;
    }

    vector<vector<string>> solveNQueens(int n) {
        rows.resize(n, -1);
        dfs(0, n);
        vector<vector<string>> str_result;
        for(auto nums: results) {
            vector<string> solution;
            for(int pos : nums) {
                string tmp(n, '.');
                tmp[pos] = 'Q';
                solution.push_back(move(tmp));
            }
            str_result.push_back(move(solution));
        }
        return str_result;
    }
};

// Runtime 7ms(>67%) | Memory Usage 7.4MB(>56%)
class Solution_2 {
    vector<vector<string>> result;
public:
    void dfs(vector<string>& bd, int pos) {
        if(pos == bd.size()) {
            result.push_back(bd);
            return;
        }
        for(int i = 0; i < bd.size(); i++) {
            if(check(bd, pos, i)) {
                bd[pos][i] = 'Q';
                dfs(bd, pos + 1);
                bd[pos][i] = '.';
            }
        }
    }

    bool check(const vector<string>& bd, int row, int col) {
        for(int i = 0; i < row; i++) {
            if(col - (i - row) >= 0 && bd[i][col - (i - row)] == 'Q')
                return false;
            if(bd[i][col] == 'Q')
                return false;
            if(col + (i - row) < bd.size() && bd[i][col + (i - row)] == 'Q')
                return false;
        }
        return true;
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> bd(n, string(n, '.'));

        dfs(bd, 0);

        return result;
    }
};