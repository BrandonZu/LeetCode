//
// Created by BrandonZu on 10/12/21.
//

#include "common.h"

// Runtime 11ms(>78%) | Memory Usage 7.7MB(>22%)
class Solution {
public:
    int strStr(string s, string p) {
        if(p.empty())
            return 0;
        int n = s.size(), m = p.size();
        s = ' ' + s, p = ' ' + p;

        vector<int> next(m + 1);
        next[1] = 0;
        for(int i = 2, j = 0; i <= m; i++) {
            while(j && p[i] != p[j + 1]) {
                j = next[j];
            }
            if(p[i] == p[j + 1]) {
                j++;
            }
            next[i] = j;
        }

        // KMP
        for(int i = 1, j = 0; i <= n; i++) {
            while(j && s[i] != p[j + 1]) {
                j = next[j];
            }
            if(s[i] == p[j + 1]) {
                j++;
            }
            if(j == m) {
                return i - m;
            }
        }
        return -1;
    }
};
