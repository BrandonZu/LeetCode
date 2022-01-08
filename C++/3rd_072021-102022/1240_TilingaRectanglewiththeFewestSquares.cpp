//
// Created by BrandonZu on 12/8/21.
//

#include "common.h"

// Runtime 5ms(>28%) | Memory Usage 5.9MB(>83%)
class Solution {
public:
    vector<int> height;
    int ans, n, m;

    void dfs(int cur) {
        if(cur >= ans) {
            return;
        }
        auto p = min_element(height.begin(), height.end());
        if(*p == m) {
            ans = cur;
            return;
        }
        int s = p - height.begin();
        int h = *p;
        int e = s;
        while(e < n && height[e] == h && (e - s + 1 + h) <= m)
            e++;
        e--;
        for(int i = e; i >= s; i--) {
            int sz = i - s + 1;
            for(int j = s; j <= i; j++) height[j] += sz;
            dfs(cur + 1);
            for(int j = s; j <= i; j++) height[j] -= sz;
        }
    }

    int tilingRectangle(int n, int m) {
        if(m > n) return tilingRectangle(m, n);
        this->n = n, this->m = m;
        ans = n * m;
        height.resize(n);
        dfs(0);
        return ans;
    }
};
