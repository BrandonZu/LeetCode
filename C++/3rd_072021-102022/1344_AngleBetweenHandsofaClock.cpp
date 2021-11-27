//
// Created by BrandonZu on 11/27/21.
//

#include "common.h"

// Runtime 0ms(>100%) | Memory Usage 5.9MB(>34%)
class Solution {
public:
    double angleClock(int hour, int minutes) {
        double h_angle = hour * 30 + minutes / 60.0 * 30.0, m_angle = minutes * 6;
        return min(abs(h_angle - m_angle), 360 - abs(h_angle - m_angle));
    }
};
