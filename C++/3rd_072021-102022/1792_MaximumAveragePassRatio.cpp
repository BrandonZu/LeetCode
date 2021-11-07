//
// Created by BrandonZu on 10/23/21.
//

#include "common.h"

// Runtime 696mb(>98%) | Memory Usage 94MB(>44%)
class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        auto profit = [&] (double pass, double total) {
            return (pass + 1) / (total + 1) - pass / total;
        };
        priority_queue<pair<double, array<int, 2>>> pq;
        double total_rate = 0;
        for(auto& p: classes) {
            total_rate += (double)p[0] / p[1];
            pq.push({profit(p[0], p[1]), {p[0], p[1]}});
        }
        while(extraStudents--) {
            auto p = pq.top();
            pq.pop();
            total_rate += p.first;
            pq.push({profit(p.second[0] + 1, p.second[1] + 1), {p.second[0] + 1, p.second[1] + 1}});
        }
        return total_rate / classes.size();
    }
};
