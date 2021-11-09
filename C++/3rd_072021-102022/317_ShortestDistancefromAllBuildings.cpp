//
// Created by BrandonZu on 11/8/21.
//

#include "common.h"

// Runtime 284ms(>86%) | Memory Usage 105MB(>37%)
class Solution {
    const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
public:
    void bfs(vector<vector<int>>& grid, vector<vector<int>>& dist_sum, int i, int j, int visited_cnt) {
        int n = grid.size(), m = grid[0].size();
        queue<pair<int, int>> q;
        q.push({i, j});
        vector<vector<int>> cur_dist_grid = grid;
        int cur_dist = 0;
        while(!q.empty()) {
            int sz = q.size();
            cur_dist++;
            for(int i = 0; i < sz; i++) {
                auto p = q.front();
                q.pop();
                for(int d = 0; d < 4; d++) {
                    int new_x = p.first + dx[d], new_y = p.second + dy[d];
                    if(new_x >= 0 && new_x < n && new_y >= 0 && new_y < m && grid[new_x][new_y] == visited_cnt) {
                        dist_sum[new_x][new_y] += cur_dist;
                        grid[new_x][new_y]--;
                        q.push({new_x, new_y});
                    }
                }
            }
        }
    }

    int shortestDistance(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dist_sum = grid;
        int min_dist = INT_MAX;
        int build_cnt = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] != 1) continue;
                bfs(grid, dist_sum, i, j, build_cnt);
                build_cnt--;
            }
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == build_cnt)
                    min_dist = min(min_dist, dist_sum[i][j]);
            }
        }
        return min_dist == INT_MAX ? -1 : min_dist;
    }
};


class Solution_TLE {
    const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
public:
    int bfs(vector<vector<int>> grid, int i, int j, int target) {
        int n = grid.size(), m = grid[0].size();
        queue<pair<int, int>> q;
        q.push({i, j});
        grid[i][j] = 3;
        int cur_dist = 0;
        int dist_sum = 0;
        while(!q.empty() && target != 0) {
            cur_dist++;
            int sz = q.size();
            for(int i = 0; i < sz; i++) {
                auto p = q.front();
                q.pop();
                for(int d = 0; d < 4; d++) {
                    int new_x = p.first + dx[d], new_y = p.second + dy[d];
                    if(new_x >= 0 && new_x < n && new_y >= 0 && new_y < m && grid[new_x][new_y] != 2 && grid[new_x][new_y] != 3) {
                        if(grid[new_x][new_y] == 1) {
                            dist_sum += cur_dist;
                            target--;
                            grid[new_x][new_y] = 3;
                        }
                        else {
                            grid[new_x][new_y] = 3;
                            q.push({new_x, new_y});
                        }
                    }
                }
            }
        }
        return target == 0 ? dist_sum : -1;
    }

    int shortestDistance(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int min_dist = INT_MAX;
        int building_cnt = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1) {
                    building_cnt++;
                }
            }
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] != 0) {
                    continue;
                }
                int res = bfs(grid, i, j, building_cnt);
                if(res != -1)
                    min_dist = min(min_dist, res);
            }
        }
        return min_dist == INT_MAX ? -1 : min_dist;
    }
};

