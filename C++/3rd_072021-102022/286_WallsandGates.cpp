//
// Created by BrandonZu on 11/28/21.
//

#include "common.h"

// Runtime 24ms(>98%) | Memory Usage 14MB(>86%)
class Solution {
    const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
    int n, m;
public:

    void wallsAndGates(vector<vector<int>>& rooms) {
        queue<pair<int, int>> q;
        n = rooms.size(), m = rooms[0].size();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(rooms[i][j] == 0) {
                    q.push({i, j});
                }
            }
        }
        int dist = 0;
        while(!q.empty()) {
            dist++;
            int sz = q.size();
            for(int i = 0; i < sz; i++) {
                auto p = q.front();
                q.pop();
                for(int d = 0; d < 4; d++) {
                    int x = p.first + dx[d], y = p.second + dy[d];
                    if(x >= 0 && x < n && y >= 0 && y < m && rooms[x][y] == INT_MAX) {
                        rooms[x][y] = dist;
                        q.push({x, y});
                    }
                }
            }
        }
    }
};

// Runtime 136ms(>10%) | Memory Usage 52MB(>7%)
class Solution_2 {
    const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
    int n, m;
public:
    void bfs(vector<vector<int>>& rooms, int i, int j) {
        unordered_set<int> visited;
        queue<pair<int, int>> q;
        q.push({i, j});
        visited.insert(i * 1000 + j);
        int dist = 0;
        while(!q.empty()) {
            dist++;
            int sz = q.size();
            for(int i = 0; i < sz; i++) {
                auto p = q.front();
                q.pop();
                for(int d = 0; d < 4; d++) {
                    int x = p.first + dx[d], y = p.second + dy[d];
                    if(x >= 0 && x < n && y >= 0 && y < m && visited.find(x * 1000 + y) == visited.end() && rooms[x][y] != -1 && rooms[x][y] != 0) {
                        visited.insert(x * 1000 + y);
                        rooms[x][y] = min(rooms[x][y], dist);
                        q.push({x, y});
                    }
                }
            }
        }
    }

    void wallsAndGates(vector<vector<int>>& rooms) {
        n = rooms.size(), m = rooms[0].size();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(rooms[i][j] == 0) {
                    bfs(rooms, i, j);
                }
            }
        }
    }
};
