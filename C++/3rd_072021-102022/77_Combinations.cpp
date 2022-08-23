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

// 1st Review 2021/8/6
class Solution_Review1 {
    vector<vector<int>> result;
    vector<int> path;
public:
    void backtrack(int n, int k, int start) {
        if(k == 0) {
            result.push_back(path);
            return;
        }
        for(int i = start; i <= n; i++) {
            path.push_back(i);
            backtrack(n, k - 1, i + 1);
            path.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        backtrack(n, k, 1);
        return result;
    }
};

// R .92 | M .55
class Solution3 {
public:
    vector<vector<int>> res;
    vector<int> path;

    vector<vector<int>> combine(int n, int k) {
        helper(n, 1, k);
        return res;
    }

    void helper(int n, int cur, int left) {
        if(!left) {
            res.push_back(path);
            return;
        }
        for(int i = cur; i <= n - left + 1; i++) {
            path.push_back(i);
            helper(n, i + 1, left - 1);
            path.pop_back();
        }
    }
};