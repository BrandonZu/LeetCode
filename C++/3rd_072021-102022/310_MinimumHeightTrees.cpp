//
// Created by BrandonZu on 11/4/21.
//

#include "common.h"

// Runtime 64ms(>85%) | Memory Usage 27MB(>81%)
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 0) return {};
        if(n == 1) return {0};
        vector<int> res;
        vector<int> degrees(n, 0);
        vector<vector<int>> adj(n, vector<int>());
        for(auto& e: edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
            degrees[e[0]]++;
            degrees[e[1]]++;
        }
        queue<int> q;
        for(int i = 0; i < n; i++) {
            if(degrees[i] == 1)
                q.push(i);
        }
        while(!q.empty()) {
            res.clear();
            int sz = q.size();
            for(int i = 0; i < sz; i++) {
                auto cur = q.front();
                q.pop();
                res.push_back(cur);
                for(int neighbour: adj[cur]) {
                    degrees[neighbour]--;
                    if(degrees[neighbour] == 1)
                        q.push(neighbour);
                }
            }
        }
        return res;
    }
};
