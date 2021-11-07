//
// Created by BrandonZu on 10/23/21.
//

#include "common.h"

// Runtime 68ms(>86%) | Memory Usage 32MB(>38%)
class Solution {
public:
    const int MOD = 1e9 + 7;
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        horizontalCuts.push_back(h), horizontalCuts.push_back(0);
        sort(horizontalCuts.begin(), horizontalCuts.end());
        verticalCuts.push_back(w), verticalCuts.push_back(0);
        sort(verticalCuts.begin(), verticalCuts.end());
        int hor_max = 0, ver_max = 0;
        for(int i = 1; i < horizontalCuts.size(); i++) {
            hor_max = max(hor_max, horizontalCuts[i] - horizontalCuts[i - 1]);
        }
        for(int i = 1; i < verticalCuts.size(); i++) {
            ver_max = max(ver_max, verticalCuts[i] - verticalCuts[i - 1]);
        }
        return ((long)(hor_max % MOD) * (ver_max % MOD)) % MOD;
    }
};
