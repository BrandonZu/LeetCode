//
// Created by BrandonZu on 10/17/21.
//

#include "common.h"

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int l = 1, r = 1e9;
        while(l < r) {
            int mid = (l + r) / 2;
            int totalTime = 0;
            for(int i: piles)
                totalTime += (i + mid - 1) / mid;
            if(totalTime <= h) {
                r = mid;
            }
            else {
                l = mid + 1;
            }
        }
        return l;
    }
};

