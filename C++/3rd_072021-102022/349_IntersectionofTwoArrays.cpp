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

// R .60 | M .93
class Solution2 {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int i = 0, j = 0;
        vector<int> res;
        while(i < nums1.size() && j < nums2.size()) {
            while(i < nums1.size() && j < nums2.size() && nums1[i] < nums2[j]) {
                i++;
            }
            while(i < nums1.size() && j < nums2.size() && nums1[i] == nums2[j]) {
                if(res.empty() || res.back() != nums1[i])
                    res.push_back(nums1[i]);
                i++, j++;
            }
            while(i < nums1.size() && j < nums2.size() && nums2[j] < nums1[i]) {
                j++;
            }
            while(i < nums1.size() && j < nums2.size() && nums1[i] == nums2[j]) {
                if(res.empty() || res.back() != nums1[i])
                    res.push_back(nums1[i]);
                i++, j++;
            }
        }
        return res;
    }
};