//
// Created by BrandonZu on 2/10/22.
//

#include "common.h"

// Runtime 4ms(>59%) | Memory Usage 8.8MB(>10%)
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        vector<int> cnt(n + 1 , 0);
        for(int c: citations) {
            cnt[min(n, c)]++;
        }
        int k = n, sum = cnt[n];
        while(k > sum) {
            k--;
            sum += cnt[k];
        }
        return k;
    }
};


// Runtime 8ms(>16%) | Memory Usage 8.7MB(>41%)
class Solution_2 {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        sort(citations.begin(), citations.end());
        for(int h = min(citations.back(), 5000); h >= 0; h--) {
            auto r = find_if(citations.begin(), citations.end(), [&citations, h](int c) -> bool {
                return c > h;
            });
            auto l = find_if(citations.begin(), citations.end(), [&citations, h](int c) -> bool {
                return c >= h;
            });
            if(n - (r - citations.begin()) <= h && h <= n - (l - citations.begin())) {
                return h;
            }
        }
        return 0;
    }
};
