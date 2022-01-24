//
// Created by BrandonZu on 1/24/22.
//

#include "common.h"

// Runtime 43ms(>38%) | Memory Usage 17.7MB(>38%)
class Solution_Optimized {
public:
    bool isReflected(vector<vector<int>>& points) {
        unordered_map<int, unordered_set<int>> pMap;
        int min_x = INT_MAX, max_x = INT_MIN;
        for(auto& p: points) {
            pMap[p[1]].insert(p[0]);
            min_x = min(min_x, p[0]);
            max_x = max(max_x, p[0]);
        }
        int target = min_x + max_x;
        for(auto& p: points) {
            if(pMap[p[1]].find(target - p[0]) == pMap[p[1]].end())
                return false;
        }
        return true;
    }
};

// Runtime 64ms(>22%) | Memory Usage 19.6MB(>23%)
class Solution {
public:
    bool isReflected(vector<vector<int>>& points) {
        unordered_map<int, unordered_set<int>> pointMap;
        for(auto& p: points) {
            pointMap[p[1]].insert(p[0]);
        }
        double mid = 0;
        bool isFirst = true;
        for(auto [k, s]: pointMap) {
            vector<int> v(s.begin(), s.end());
            sort(v.begin(), v.end());
            double cur_mid = 0;
            if(v.size() % 2 == 1)
                cur_mid = v[v.size() / 2];
            else
                cur_mid = (v[v.size() / 2] + v[v.size() / 2 - 1]) / 2.0;
            if(!isFirst && cur_mid != mid)
                return false;
            double diff = 0;
            for(int x: v) {
                diff += x - cur_mid;
            }
            if(diff != 0)
                return false;
            if(isFirst) {
                isFirst = false;
                mid = cur_mid;
            }
        }
        return true;
    }
};
