//
// Created by BrandonZu on 12/7/21.
//

#include "common.h"

// Runtime 4ms(>100%) | Memory Usage 8.7MB(>65%)
class Solution {
public:
    struct setHasher {
        int operator() (const pair<int, int>& p) const {
            return p.first * 1000 + p.second;
        }
    };

    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
    unordered_set<pair<int, int>, setHasher> visited;

    void dfs(Robot& robot, int row, int col, int dir) {
        if(visited.find({row, col}) == visited.end()) {
            visited.insert({row, col});
            robot.clean();
            for(int d = 0; d < 4; d++) {
                if(robot.move()) {
                    dfs(robot, row + dx[dir], col + dy[dir], dir);
                }
                robot.turnRight();
                dir = (dir + 1) % 4;
            }
        }
        // Move Back
        robot.turnRight(), robot.turnRight();
        robot.move();
        robot.turnRight(), robot.turnRight();
    }

    void cleanRoom(Robot& robot) {
        dfs(robot, 0, 0, 0);
    }
};
