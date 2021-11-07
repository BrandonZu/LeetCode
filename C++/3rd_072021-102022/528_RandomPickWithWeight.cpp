//
// Created by BrandonZu on 11/6/21.
//

#include "common.h"

// Runtime 84ms(>66%) | Memory Usage 40.2MB(>98%)
class Solution {
    int total_sum = 0;
    vector<int> pref_sum;
public:
    Solution(vector<int>& w) {
        int n = w.size();
        pref_sum = w;
        for(int i = 1; i < n; i++) {
            pref_sum[i] += pref_sum[i - 1];
        }
        total_sum = pref_sum[n - 1];
    }

    int pickIndex() {
        int rand_index = rand() % total_sum + 1;
        auto pos = lower_bound(pref_sum.begin(), pref_sum.end(), rand_index);
        return pos - pref_sum.begin();
    }
};
