//
// Created by BrandonZu on 11/16/21.
//

#include "common.h"

// Runtime 56ms(>92%) | Memory Usage 14.6MB(>38%)
class Solution {
    const int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
public:
    struct node {
        int h;
        int x, y;
        bool operator< (const node& a) const {
            return h > a.h;
        }
    };

    int trapRainWater(vector<vector<int>>& heightMap) {
        int n = heightMap.size(), m = heightMap[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        priority_queue<node> pq;
        for(int i = 0; i < n; i++) {
            visited[i][0] = visited[i][m - 1] = true;
            pq.push({heightMap[i][0], i, 0});
            pq.push({heightMap[i][m - 1], i, m - 1});
        }

        for(int j = 0; j < m; j++) {
            visited[0][j] = visited[n - 1][j] = true;
            pq.push({heightMap[0][j], 0, j});
            pq.push({heightMap[n - 1][j], n - 1, j});
        }

        int res = 0;
        while(!pq.empty()) {
            auto cur = pq.top();
            pq.pop();
            res += cur.h - heightMap[cur.x][cur.y];
            for(int i = 0; i < 4; i++) {
                int x = cur.x + dx[i], y = cur.y + dy[i];
                if(x >= 0 && x < n && y >= 0 && y < m && !visited[x][y]) {
                    visited[x][y] = true;
                    pq.push({max(cur.h, heightMap[x][y]), x, y});
                }
            }
        }
        return res;
    }
};

// l_max / r_max alone is not enough
class WrongSolution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int n = heightMap.size(), m = heightMap[0].size();
        vector<vector<int>> leftRight(n, vector<int>(m));
        vector<vector<int>> topDown(n, vector<int>(m));

        for(int i = 0; i < n; i++) {
            int l_max = 0, r_max = 0;
            int l = 0, r = m - 1;
            while(l <= r) {
                if(l_max < r_max) {
                    leftRight[i][l] = max(0, l_max - heightMap[i][l]); // Not Enough
                    l_max = max(l_max, heightMap[i][l]);
                    l++;
                }
                else {
                    leftRight[i][r] = max(0, r_max - heightMap[i][r]); // Not Enough
                    r_max = max(r_max, heightMap[i][r]);
                    r--;
                }
            }
        }

        for(int j = 0; j < m; j++) {
            int t_max = 0, b_max = 0;
            int t = 0, b = n - 1;
            while(t <= b) {
                if(t_max < b_max) {
                    topDown[t][j] = max(0, t_max - heightMap[t][j]); // Not Enough
                    t_max = max(t_max, heightMap[t][j]);
                    t++;
                }
                else {
                    topDown[b][j] = max(0, b_max - heightMap[b][j]); // Not Enough
                    b_max = max(b_max, heightMap[b][j]);
                    b--;
                }
            }
        }

        int res = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                res += min(leftRight[i][j], topDown[i][j]);
            }
        }
        return res;
    }
};
