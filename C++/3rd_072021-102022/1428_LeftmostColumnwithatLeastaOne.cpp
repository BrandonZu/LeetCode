//
// Created by BrandonZu on 11/17/21.
//

#include "common.h"

// Runtime 8ms(>75%) | Memory Usage 8.2MB(>65%)
class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        auto p = binaryMatrix.dimensions();
        int n = p[0], m = p[1];
        int i = 0, j = m - 1;
        while(i < n && j >= 0) {
            if(binaryMatrix.get(i, j) == 0) {
                i++;
            }
            else {
                j--;
            }
        }
        if(j == m - 1)
            return -1;
        else
            return j + 1;
    }
};

// Runtime 8ms(>75%) | Memory Usage 8.2MB(>65%)
class Solution_BinarySearch {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        auto p = binaryMatrix.dimensions();
        int n = p[0], m = p[1];
        int l_most = n;
        for(int i = 0; i < n; i++) {
            int l = 0, r = m - 1;
            while(l < r) {
                int mid = l + r >> 1;
                if(binaryMatrix.get(i, mid) == 1) {
                    r = mid;
                }
                else {
                    l = mid + 1;
                }
            }
            if(binaryMatrix.get(i, l) == 1)
                l_most = min(l_most, l);
        }
        return l_most == n ? -1 : l_most;
    }
};

