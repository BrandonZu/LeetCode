//
// Created by BrandonZu on 2021/8/12.
//

#include "common.h"

// Runtime 44ms(>12.53%) | Memory Usage 17.6MB(>31%)
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int pos = 0;
        int res = 0;
        for(int i = 0; i < g.size(); i++) {
            while(pos < s.size() && s[pos] < g[i]) pos++;
            if(pos >= s.size())
                break;
            else
                res++, pos++;
        }
        return res;
    }
};
