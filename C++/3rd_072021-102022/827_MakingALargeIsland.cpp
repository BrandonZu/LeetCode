//
// Created by BrandonZu on 11/6/21.
//

#include "common.h"

class Solution_UnionFind {
public:
    int largestIsland(vector<vector<int>>& grid) {

    }
};

// Runtime 960ms(>33%) | Memory Usage 349MB(>7%)
class Solution_BFS_Iteration {
public:
    const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
    int n, m;

    int getArea(vector<vector<int>>& grid, int start_x, int start_y, int index) {
        int cur_area = 0;
        queue<pair<int, int>> q;

        grid[start_x][start_y] = index;
        cur_area++;
        q.push({start_x, start_y});

        while(!q.empty()) {
            auto p = q.front();
            q.pop();

            for(int i = 0; i < 4; i++) {
                int new_x = p.first + dx[i], new_y = p.second + dy[i];
                if(new_x >= 0 && new_x < n && new_y >= 0 && new_y < m && grid[new_x][new_y] == 1) {
                    grid[new_x][new_y] = index;
                    cur_area++;
                    q.push({new_x, new_y});
                }
            }
        }
        return cur_area;
    }

    int largestIsland(vector<vector<int>>& grid) {
        vector<int> islands(2);
        n = grid.size(), m = grid[0].size();
        // Calculate the area of islands
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] != 1)
                    continue;
                int area = getArea(grid, i, j, islands.size());
                islands.push_back(area);
            }
        }
        //
        int max_area = 1;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] != 0) {
                    max_area = max(max_area, islands[grid[i][j]]);
                    continue;
                }
                int tmp = 1;
                unordered_set<int> island_set;
                for(int tt = 0; tt < 4; tt++) {
                    int new_x = i + dx[tt], new_y = j + dy[tt];
                    if(new_x >= 0 && new_x < n && new_y >= 0 && new_y < m)
                        island_set.insert(grid[new_x][new_y]);
                }
                for(auto& p: island_set) tmp += islands[p];
                max_area = max(max_area, tmp);
            }
        }
        return max_area;
    }
};

// Runtime 472ms(>85%) | Memory Usage 144MB(>77%)
class Solution_BFS_Recursion {
public:
    const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

    inline int get(vector<vector<int>>& grid, int i, int j) {
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size())
            return -1;
        else
            return grid[i][j];
    }

    int paint(vector<vector<int>>& grid, int i, int j, int index) {
        if(get(grid, i, j) != 1)
            return 0;
        grid[i][j] = index;
        int res = 1;
        for(int dir = 0; dir < 4; dir++) {
            res += paint(grid, i + dx[dir], j + dy[dir], index);
        }
        return res;
    }

    int largestIsland(vector<vector<int>>& grid) {
        vector<int> islands(2);
        int n = grid.size(), m = grid[0].size();
        // Paint the island
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] != 1)
                    continue;
                int area = paint(grid, i, j, (int)islands.size());
                islands.push_back(area);
            }
        }
        // Flip the 0
        int res = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 0) {
                    unordered_set<int> s;
                    int tmp = 1;
                    for(int dir = 0; dir < 4; dir++) {
                        if(get(grid, i + dx[dir], j + dy[dir]) >= 2)
                            s.insert(get(grid, i + dx[dir], j + dy[dir]));
                    }
                    for(auto& p: s) tmp += islands[p];
                    res = max(res, tmp);
                }
            }
        }
        return res == 0 ? n * m : res;
    }
};

int main() {
    vector<vector<int>> grid = {{1, 0}, {0, 1}};
    Solution_BFS_Recursion s;
    cout << s.largestIsland(grid) << endl;
}
