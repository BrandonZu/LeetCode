#include<cmath>
#include<iostream>
using namespace std;
class Solution {
    int* position;
    int total_count;
    int total;
public:
    bool check(int row, int col) {
        for(int i = 0; i < row; i++) {
            if(position[i] == col || abs(position[i] - col) == abs(row - i))
                return false;
        }
        return true;
    }

    int totalNQueens(int n) {
        position = new int[n];
        for(int i = 0; i < n; i++)
            position[i] = -1;
        total = n;
        total_count = 0;
        dfs(0);
        return total_count;
    }

    void dfs(int row) {
        if(row == total) {
            total_count++;
            return;
        }
        for(int i = 0; i < total; i++) {
            position[row] = i;
            if(check(row, i)) {
                dfs(row + 1);
            }
            position[row] = -1;
        }
    }
};