//
// Created by BrandonZu on 2021/7/15.
//

#include "vector"
using namespace std;

// Runtime 16ms(>94%) | Memory Usage 47MB(>48%)
class Solution {
    vector<int> ans;
    vector<int> status;
    vector<vector<int>> adj;
    bool flag;
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        status.resize(numCourses, 0);
        adj.resize(numCourses);
        flag = true;
        // Build Graph
        for(auto& req: prerequisites) {
            adj[req[0]].push_back(req[1]);
        }
        // DFS
        for(int i = 0; i < numCourses; i++) {
            if(status[i] == 0) {
                dfs(i);
            }
        }
        if(flag)
            return ans;
        else
            return {};
    }

    void dfs(int cur) {
        if(!flag) return;

        status[cur] = 1;
        for(int node: adj[cur]) {
            if(status[node] == 0) {
                dfs(node);
            }
            else if(status[node] == 1) {
                flag = false;
                return;
            }
            else if(status[node] == 2) {
                continue;
            }
        }
        status[cur] = 2;
        ans.push_back(cur);
    }
};