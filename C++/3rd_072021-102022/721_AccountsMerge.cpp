//
// Created by BrandonZu on 11/5/21.
//

#include "common.h"

// Runtime 76ms(>94%) | Memory Usage 38MB(>70%)
class Solution {
public:
    vector<int> p;

    int find(int x) {
        if(p[x] != x) {
            p[x] = find(p[x]);
        }
        return p[x];
    }

    void merge(int parent, int child) {
        if(find(parent) == find(child))
            return;
        p[find(child)] = find(parent);
    }

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        p.resize(n);
        for(int i = 0; i < n; i++) {
            p[i] = i;
        }
        unordered_map<string, vector<int>> acct_map;
        for(int i = 0; i < n; i++) {
            for(int j = 1; j < accounts[i].size(); j++) {
                acct_map[accounts[i][j]].push_back(i);
            }
        }
        // Merge Accounts
        for(auto& [k, v]: acct_map) {
            for(int i = 1; i < v.size(); i++) {
                merge(v[0], v[i]);
            }
        }

        vector<set<string>> remove_dup(n);
        for(int i = 0; i < n; i++) {
            int cur = find(i);
            for(int j = 1; j < accounts[i].size(); j++) {
                remove_dup[cur].insert(accounts[i][j]);
            }
        }

        vector<vector<string>> result;
        for(int i = 0; i < n; i++) {
            if(!remove_dup[i].empty()) {
                vector<string> tmp;
                tmp.push_back(accounts[i][0]);
                for(auto& str: remove_dup[i]) tmp.push_back(str);
                result.push_back(tmp);
            }
        }

        return result;
    }
};
