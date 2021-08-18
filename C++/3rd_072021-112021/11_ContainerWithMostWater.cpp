//
// Created by BrandonZu on 2021/8/15.
//

#include "common.h"

// Runtime 84ms(>60%) | Memory usage 59MB(>80%)
class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxCap = 0;
        int l = 0, r = height.size() - 1;
        while(l < r) {
            maxCap = max(maxCap, (r - l) * min(height[l], height[r]));
            int next;
            if(height[l] < height[r]) {
                // Move Left Pointer
                next = l + 1;
                while(next < r && height[next] <= height[l])
                    next++;
                l = next;
            }
            else {
                // Move Right Pointer
                next = r - 1;
                while(next > l && height[next] <= height[r])
                    next--;
                r = next;
            }
        }
        return maxCap;
    }
};
