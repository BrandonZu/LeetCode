//
// Created by BrandonZu on 10/26/21.
//

#include "common.h"

// Runtime 12ms(>98%) | Memory Usage 12MB(>82%)
class Solution {
    vector<int> p;
public:
    int find(int x) {
        if(p[x] != x)
            p[x] = find(p[x]);
        return p[x];
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        p.resize(n);
        for(int i = 0; i < n; i++) {
            p[i] = i;
        }
        for(auto& e: edges) {
            p[find(e[0])] = find(e[1]);
        }
        unordered_set<int> used;
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            if(used.find(find(i)) == used.end()) {
                used.insert(find(i));
                cnt++;
            }
        }
        return cnt;
    }
};
