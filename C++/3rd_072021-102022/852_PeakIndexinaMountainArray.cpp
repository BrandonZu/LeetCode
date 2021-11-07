//
// Created by BrandonZu on 2021/7/18.
//

#include "common.h"

// Runtime 4ms(>100%) | Memory Usage 12MB(>41%)
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        if(arr.size() == 1) return arr[0];
        int l = 1, r = arr.size() - 1;
        while(l < r) {
            int mid = l + r + 1 >> 1;
            if(arr[mid] > arr[mid - 1])
                l = mid;
            else
                r = mid - 1;
        }
        return l;
    }
};
