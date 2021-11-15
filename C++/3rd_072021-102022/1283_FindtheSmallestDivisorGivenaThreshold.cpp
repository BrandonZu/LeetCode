//
// Created by BrandonZu on 11/14/21.
//

#include "common.h"

// Runtime 36ms(>92%) | Memory Usage 22MB(>92%)
class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int l = 1, r = 1;
        for(int num: nums)
            r = max(r, num);
        while(l < r) {
            int mid = (l + r) >> 1;
            bool flag = true;
            int tmp = 0;
            for(int num: nums) {
                tmp += ceil((double)num / mid);
                if(tmp > threshold) {
                    flag = false;
                    break;
                }
            }

            if(flag) {
                r = mid;
            }
            else {
                l = mid + 1;
            }
        }
        return l;
    }
};

