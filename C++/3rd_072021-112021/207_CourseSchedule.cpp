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

// 1st Review
// Runtime 20ms(>78%) | Memory Usage 13.8MB(>65%)
class Solution_R1 {
    // 0: Unvisited  1: Visiting  2: Visited
    vector<int> status;
    vector<vector<int>> adj;
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        adj.resize(numCourses);
        status.resize(numCourses, 0);
        for(auto& req: prerequisites) {
            adj[req[0]].push_back(req[1]);
        }
        for(int i = 0; i < numCourses; i++) {
            if(status[i] != 0) {
                continue;
            }
            if(!dfs(i))
                return false;
        }
        return true;
    }

    bool dfs(int cur) {
        for(int node: adj[cur]) {
            if(status[node] == 2)
                continue;
            else if(status[node] == 1)
                return false;
            else {
                status[node] = 1;
                if(!dfs(node))
                    return false;
                status[node] = 2;
            }
        }
        return true;
    }
};