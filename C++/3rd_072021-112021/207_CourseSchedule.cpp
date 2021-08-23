//
// Created by BrandonZu on 2021/7/15.
//

#include "common.h"

// Runtime 20ms(>73%) | Memory Usage 13.4MB(>78%)
class Solution_DFS {
    vector<int> status;
    vector<vector<int>> adj;
public:
    bool dfs(int node) {
        status[node] = 1;
        for(int i = 0; i < adj[node].size(); i++) {
            if(status[adj[node][i]] == 1)
                return false;
            if(status[adj[node][i]] == 0 && !dfs(adj[node][i]))
                return false;
        }
        status[node] = 2;
        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        status.resize(numCourses);
        status.resize(numCourses, 0);
        adj.resize(numCourses);
        // Build Graph
        for(auto& item: prerequisites) {
            adj[item[1]].push_back(item[0]);
        }
        // Check Cyclic
        for(int i = 0; i < numCourses; i++) {
            if(status[i] == 0 && !dfs(i))
                return false;
        }
        return true;
    }
};
