//
// Created by BrandonZu on 11/30/21.
//

#include "common.h"

// Runtime 228ms(>88%) | Memory Usage 19.3MB(>97%)
class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        unordered_set<int> p_hash;
        for(auto& p: points) {
            p_hash.insert(p[0] * 1000 + p[1]);
        }
        int n = points.size();
        int min_area = INT_MAX;
        int x1, y1, x2, y2;
        for(int i = 0; i < n; i++) {
            x1 = points[i][0], y1 = points[i][1];
            for(int j = i + 1; j < n; j++) {
                x2 = points[j][0], y2 = points[j][1];
                if(x1 != x2 && y1 != y2 && p_hash.find(x1 * 1000 + y2) != p_hash.end() && p_hash.find(x2 * 1000 + y1) != p_hash.end()) {
                    min_area = min(min_area, abs(x1 - x2) * abs(y1 - y2));
                }
            }
        }
        if(min_area == INT_MAX)
            return 0;
        else
            return min_area;
    }
};
