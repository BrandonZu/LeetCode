//
// Created by BrandonZu on 2021/7/25.
//

#include "common.h"

// Runtime 4ms(>95%) | Memory Usage 8.8MB(>50%)
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.empty() || nums2.empty()) return {};
        vector<int> result(nums1.size());
        unordered_map<int, int> myMap;
        stack<int> stk;
        for(int i = nums2.size() - 1; i >= 0; i--) {
            // Maintain a Monotonic Decreasing Stack
            while(!stk.empty() && stk.top() <= nums2[i])
                stk.pop();
            if(stk.empty())
                myMap[nums2[i]] = -1;
            else
                myMap[nums2[i]] = stk.top();
            stk.push(nums2[i]);
        }

        for(int i = 0; i < nums1.size(); i++)
            result[i] = myMap[nums1[i]];

        return result;
    }
};

