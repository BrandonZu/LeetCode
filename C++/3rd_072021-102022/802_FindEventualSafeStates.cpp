//
// Created by BrandonZu on 11/7/21.
//

#include "common.h"

// Runtime 136ms(>90%) | Memory Usage 47MB(>53%)
class Solution {
    enum NODE_STATE {
        unvisited, visiting, valid, invalid
    };
    vector<NODE_STATE> state;
public:
    bool dfs(vector<vector<int>>& graph, int node) {
        state[node] = visiting;
        bool flag = true;
        for(int i = 0; i < graph[node].size(); i++) {
            if(state[graph[node][i]] == visiting || state[graph[node][i]] == invalid) {
                flag = false;
            }
            else if(state[graph[node][i]] == unvisited) {
                if(!dfs(graph, graph[node][i])) {
                    flag = false;
                }
            }
        }
        state[node] = flag ? valid : invalid;
        return flag;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        state.resize(n, NODE_STATE::unvisited);
        vector<int> result;
        for(int i = 0; i < n; i++) {
            if(state[i] == unvisited && dfs(graph, i)) {
                result.push_back(i);
            }
            else if(state[i] == valid) {
                result.push_back(i);
            }
        }
        return result;
    }
};
