//
// Created by BrandonZu on 2021/8/1.
//

#include "common.h"

// Runtime 24ms(>98%) | Memory Usage 18MB(>99%)
class Solution_DFS {
    const int x_dir[4] = {1, -1, 0, 0};
    const int y_dir[4] = {0, 0, 1, -1};
public:
    inline bool isValid(vector<vector<int>>& maze, int x, int y) {
        if(x >= 0 && x < maze.size() && y >= 0 && y < maze[0].size() && maze[x][y] != 1)
            return true;
        else
            return false;
    }

    inline bool shouldVisit(vector<vector<int>>& maze, int x, int y) {
        if(x >= 0 && x < maze.size() && y >= 0 && y < maze[0].size() && maze[x][y] == 0)
            return true;
        else
            return false;
    }

    bool backtrack(vector<vector<int>>& maze, int pos_x, int pos_y, int dest_x, int dest_y) {
        if (pos_x == dest_x && pos_y == dest_y)
            return true;

        maze[pos_x][pos_y] = -1;
        for(int i = 0; i < 4; i++) {
            // Save the origin coordinates
            int tmp_x = pos_x, tmp_y = pos_y;

            pos_x += x_dir[i], pos_y += y_dir[i];
            while(isValid(maze, pos_x, pos_y))
                pos_x += x_dir[i], pos_y += y_dir[i];
            pos_x -= x_dir[i], pos_y -= y_dir[i];
            // Important
            if(shouldVisit(maze, pos_x, pos_y))
                if(backtrack(maze, pos_x, pos_y, dest_x, dest_y))
                    return true;

            // Return to the original coordinates
            pos_x = tmp_x, pos_y = tmp_y;
        }
        return false;
    }

    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        return backtrack(maze, start[0], start[1], destination[0], destination[1]);
    }
};

class Solution_BFS {
    const int x_dir[4] = {1, -1, 0, 0};
    const int y_dir[4] = {0, 0, 1, -1};
public:
    inline bool isValid(vector<vector<int>>& maze, int x, int y) {
        if(x >= 0 && x < maze.size() && y >= 0 && y < maze[0].size() && maze[x][y] != 1)
            return true;
        else
            return false;
    }

    inline bool shouldVisit(vector<vector<int>>& maze, int x, int y) {
        if(x >= 0 && x < maze.size() && y >= 0 && y < maze[0].size() && maze[x][y] == 0)
            return true;
        else
            return false;
    }

    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        queue<pair<int, int>> q;
        q.push({start[0], start[1]});
        // BFS
        while(!q.empty()) {
            auto cur = q.front();
            q.pop();
            maze[cur.first][cur.second] = -1;
            for(int i = 0; i < 4; i++) {
                auto tmp = cur;
                while(isValid(maze, tmp.first, tmp.second))
                    tmp.first += x_dir[i], tmp.second += y_dir[i];
                tmp.first -= x_dir[i], tmp.second -= y_dir[i];
                if(tmp.first == destination[0] && tmp.second == destination[1])
                    return true;
                if(shouldVisit(maze, tmp.first, tmp.second))
                    q.push(tmp);
            }
        }

        return false;
    }
};

