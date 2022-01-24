//
// Created by BrandonZu on 1/24/22.
//

#include "common.h"

// Runtime 28ms(>32%) | Memory Usage 12.9MB(>15%)
class Solution_Optimized {
public:
    int maxPoints(vector<vector<int>>& points) {
        int ans = 1;
        for(auto& p: points) {
            unordered_map<long double, int> cnt;
            int ver = 0;
            for(auto& q: points) {
                if(p == q) continue;
                if(p[0] == q[0])
                    ver++;
                else {
                    long double k = (long double)(p[1] - q[1]) / (p[0] - q[0]);
                    cnt[k]++;
                }
            }
            for(auto& c: cnt) {
                ans = max(ans, c.second + 1);
            }
            ans = max(ans, ver + 1);
        }
        return ans;
    }
};

// Runtime 12ms(>77%) | Memory Usage MB()
class Solution {
public:
    bool isOnSameLine(double k, double b, vector<int>& point) {
        // IMPORTANT! Do not use '==' to judge if two double is equal
        return abs(point[1] - k * point[0] - b) < 1e-6;
    }

    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        int maxLen = 1;
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                int tmp = 0;
                if(points[i][0] == points[j][0]) {
                    for (auto &p: points) {
                        if (p[0] == points[i][0])
                            tmp++;
                    }
                }
                else {
                    double k = (double)(points[i][1] - points[j][1]) / (points[i][0] - points[j][0]);
                    double b = (double)points[i][1] - k * points[i][0];
                    for (auto &p: points) {
                        if (isOnSameLine(k, b, p))
                            tmp++;
                    }
                }
                maxLen = max(tmp, maxLen);
            }
        }
        return maxLen;
    }
};
