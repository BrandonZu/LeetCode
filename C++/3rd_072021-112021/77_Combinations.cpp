//
// Created by BrandonZu on 2021/7/29.
//

#include "common.h"

// Runtime 8ms(>98%) | Memory Usage 8.9MB(>98%)
class Solution {
    vector<int> path;
public:
    void dfs(vector<vector<int>>& result, int cnt, int last, int n) {
        if(cnt == 0) {
            result.push_back(path);
            return;
        }
        // Optimized: Leave at least (cnt - 1) elements for future recursion
        for(int i = last + 1; i <= n - cnt + 1; i++) {
            path[cnt - 1] = i;
            dfs(result, cnt - 1, i, n);
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        path.resize(k);
        dfs(result, k, 0, n);
        return result;
    }
};
