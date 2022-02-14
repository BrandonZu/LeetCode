//
// Created by BrandonZu on 2/14/22.
//

#include "common.h"

// Runtime 8ms(>68%) | Memory Usage 5.8MB(>80%)
class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int area = 0;
        area += abs(ax1 - ax2) * abs(ay1 - ay2);
        area += abs(bx1 - bx2) * abs(by1 - by2);
        if(max(ax1, bx1) < min(ax2, bx2) && max(ay1, by1) < min(ay2, by2)) {
            area -= (min(ax2, bx2) - max(ax1, bx1)) * (min(ay2, by2) - max(ay1, by1));
        }
        return area;
    }
};
