//
// Created by BrandonZu on 11/27/21.
//

#include "common.h"

// Runtime 244ms(>33%) | Memory Usage 92.4MB(>92%)
class Solution {
public:
    int maxLength(vector<int>& ribbons, int k) {
        long cnt = 0;
        for(int i: ribbons) {
            cnt += i;
            if(cnt > k) break;
        }
        if(cnt < k) return 0;
        int l = 1, r = 1e5;
        while(l < r) {
            int mid = l + r + 1 >> 1;
            int cnt = 0;
            for(int i: ribbons) cnt += i / mid;
            if(cnt >= k) {
                l = mid;
            }
            else {
                r = mid - 1;
            }
        }
        return l;
    }
};
