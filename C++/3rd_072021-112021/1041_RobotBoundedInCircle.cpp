//
// Created by BrandonZu on 9/26/21.
//

#include "common.h"

// Runtime 0ms(>100%) | Memory Usage 6.2MB(>50%)
class Solution {
public:
    bool isRobotBounded(string instructions) {
        int dx[4] = {1, 0, -1, 0};
        int dy[4] = {0, 1, 0, -1};
        int x = 0, y = 0;
        int dir = 0;
        for(char c: instructions) {
            if(c == 'G') {
                x += dx[dir];
                y += dy[dir];
            }
            else if(c == 'L') {
                dir = (dir + 3) % 4;
            }
            else if(c == 'R') {
                dir = (dir + 1) % 4;
            }
        }
        return (x == 0 && y == 0) || dir != 0;
    }
};

// 1st Review 10/21/2021
class Solution_R1 {
public:
    bool isRobotBounded(string instructions) {
        const int i_dir = {0, 0, 1, -1};
        const int j_dir = {1, -1, 0, 0};

    }
};