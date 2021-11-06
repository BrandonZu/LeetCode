//
// Created by BrandonZu on 11/5/21.
//

#include "common.h"

// Runtime ms() | Memory Usage
class Solution {
public:
    vector<int> p;

    int find(int x) {
        if(p[x] != x) {
            p[x] = find(x);
        }
        return x;
    }

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        p.resize(n);
        for(int i = 0; i < n; i++) {
            p[i] = i;
        }
        unordered_map<string, vector<int>> acct_map;
        for(vector<string>& acct: accounts) {
            string cur_email = acct[0];
            for(int i = 1; i < acct.size(); i++) {
                acct_map[cur_email].push_back(acct[i]);
            }

        }

        vector<vector<int>> result;

        return result;
    }
};
