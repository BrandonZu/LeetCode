//
// Created by BrandonZu on 11/23/21.
//


#include "common.h"

struct VectorHasher {
    int operator()(const vector<int> &V) const {
        long hash = V.size();
        for(auto &i : V) {
            hash ^= i + 0x9e3779b9 + (hash << 6) + (hash >> 2);
        }
        return (int)hash;
    }
};

class Solution {
    const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        int n = board.size(), m = board[0].size();
        vector<int> start, end = {1, 2, 3, 4, 5, 0};
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                start.push_back(board[i][j]);
            }
        }

        queue<vector<int>> q;
        unordered_map<vector<int>, int, VectorHasher> dist;
        q.push(start);
        int cnt = 0;
        while(!q.empty()) {
            cnt++;
            int size = q.size();
            for(int tt = 0; tt < size; tt++) {
                auto cur = q.front();
                q.pop();
                if(cur == end) {
                    return dist[end];
                }

                int pos = find(cur.begin(), cur.end(), 0) - cur.begin();
                int i = pos / m, j = pos % m;
                for(int dir = 0; dir < 4; dir++) {
                    int x = i + dx[dir], y = j + dy[dir];
                    if(x >= 0 && x < n && y >= 0 && y < m) {
                        swap(cur[pos], cur[x * m + y]);
                        if(dist.find(cur) == dist.end()) {
                            dist[cur] = cnt;
                            q.push(cur);
                        }
                        swap(cur[pos], cur[x * m + y]);
                    }
                }
            }
        }
        return -1;
    }
};
