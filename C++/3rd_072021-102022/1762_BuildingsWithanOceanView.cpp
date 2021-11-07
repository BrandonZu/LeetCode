//
// Created by BrandonZu on 11/3/21.
//

#include "common.h"

// Rutime 124ms(>92%) | Memory Usage 69MB(>88%)
class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {
        int n = heights.size();
        vector<int> buildings;
        for(int i = n - 1; i >= 0; i--) {
            if(buildings.empty() || heights[buildings.back()] < heights[i]) {
                buildings.push_back(i);
            }
        }
        sort(buildings.begin(), buildings.end());
        return buildings;
    }
};
