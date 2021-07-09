#include <vector>
#include <iostream>
using namespace std;
/*
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        int rowSize = matrix.size();
        if(rowSize == 0)
            return {};
        int colSize = matrix[0].size();
        for(int round = 0; round < (rowSize + 1) / 2; round++) {
            for(int j = round; j < colSize - round; j++)
                result.push_back(matrix[round][j]);
            for(int i = round + 1; i < rowSize - round; i++)
                result.push_back(matrix[i][colSize - 1 - round]);
            for(int j = colSize - 2 - round; j >= round && rowSize - 1 - round != round; j--)
                result.push_back(matrix[rowSize - round - 1][j]);
            for(int i = rowSize - 2 - round; i >= round + 1 && colSize - 1 - round != round; i--)
                result.push_back(matrix[i][round]);
        }
        return result;
    }
};
*/
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        if(matrix.empty())
            return result;
        int up = 0;
        int down = matrix.size() - 1;
        int left = 0;
        int right = matrix[0].size() - 1;
        while(true) {
            for(int i = left; i <= right; ++i)
                result.push_back(matrix[up][i]);
            if(++up > down) break;
            for(int j = up; j <= down; j++)
                result.push_back(matrix[j][right]);
            if(--right < left) break;
            for(int j = right; j >= left; j--)
                result.push_back(matrix[down][j]);
            if(--down < up) break;
            for(int i = down; i >= up; i--)
                result.push_back(matrix[i][left]);
            if(++left > right) break;

        }
        return result;
    }
};
