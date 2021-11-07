//
// Created by BrandonZu on 10/20/21.
//

#include "common.h"

// Runtime 34ms(>34%) | Memory Usage 13.7MB(>89%)
class Solution {
    vector<bool> visited;
public:
    void dfs(vector<vector<int>>& isConnected, int node) {
        visited[node] = true;
        for(int i = 0; i < isConnected[node].size(); i++) {
            if(isConnected[node][i] == 1 && !visited[i]) {
                dfs(isConnected, i);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int count = 0;
        visited.resize(isConnected.size(), false);
        for(int i = 0; i < isConnected.size(); i++) {
            if(!visited[i]) {
                dfs(isConnected, i);
                count++;
            }
        }
        return count;
    }
};
