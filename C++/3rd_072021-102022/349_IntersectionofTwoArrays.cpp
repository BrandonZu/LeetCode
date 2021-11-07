//
// Created by BrandonZu on 2021/7/23.
//

#include "common.h"

// Runtime 4ms(>92%) | Memory Usage 10.4MB(>53%)
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> m(nums2.begin(), nums2.end());
        vector<int> result;
        for(int x: nums1) {
            if(m.count(x)) {
                m.erase(x);
                result.push_back(x);
            }
        }
        return result;
    }
};