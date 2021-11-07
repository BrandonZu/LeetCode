//
// Created by BrandonZu on 10/23/21.
//

#include "common.h"

// Runtime 180ms(>93%) | Memory Usage 25MB(>55%)
class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> num_map;
        int result = 0;
        for(int a: nums1) {
            for(int b: nums2) {
                num_map[a + b]++;
            }
        }
        for(int c: nums3) {
            for(int d: nums4) {
                result += num_map[-(c + d)];
            }
        }
        return result;
    }
};
