//
// Created by BrandonZu on 12/7/21.
//

#include "common.h"

// Runtime 8ms(>28%) | Memory Usage 10.5MB(>5.8%)
class Solution {
    string path;
    unordered_map<char, unordered_set<char>> adj;
    unordered_map<char, int> status;
public:
    bool dfs(char c) {
        status[c] = 1;
        for(auto adj: adj[c]) {
            if(status[adj] == 1) {
                return true;
            }
            else if(status[adj] == 0) {
                if(dfs(adj))
                    return true;
            }
        }
        status[c] = 2;
        path.push_back(c);
        return false;
    }

    string alienOrder(vector<string>& words) {
        // Build graph
        for(char c = 'a'; c <= 'z'; c++) {
            status[c] = 0;
        }
        for(auto& w: words) {
            for(char c: w) {
                adj.insert({c, {}});
            }
        }
        for(int i = 0; i < words.size() - 1; i++) {
            int len = min(words[i].size(), words[i + 1].size());
            int j;
            for(j = 0; j < len; j++) {
                if(words[i][j] != words[i + 1][j])
                    break;
            }
            if(j < len)
                adj[words[i][j]].insert(words[i + 1][j]);
            else if(words[i].size() > words[i + 1].size())
                return "";
        }
        // DFS
        for(auto p: adj) {
            if(status[p.first] == 0)
                if(dfs(p.first))
                    return "";
        }
        reverse(path.begin(), path.end());
        return path;
    }
};
