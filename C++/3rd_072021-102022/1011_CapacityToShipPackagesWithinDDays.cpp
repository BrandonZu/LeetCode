//
// Created by BrandonZu on 11/27/21.
//

#include "common.h"

// Runtime 40ms(>87%) | Memory Usage 26MB(>26%)
class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int max_w = 0;
        for(int w: weights) max_w = max(max_w, w);
        int l = max_w, r = 500 * 5 * 1e4 + 1;
        while(l < r) {
            int mid = l + r >> 1;

            int cnt = 1;
            int tmp = 0;
            for(int w: weights) {
                if(tmp + w <= mid) {
                    tmp += w;
                }
                else {
                    tmp = w;
                    cnt++;
                }
            }
            if(cnt <= days) {
                r = mid;
            }
            else {
                l = mid + 1;
            }
        }
        return l;
    }
};
