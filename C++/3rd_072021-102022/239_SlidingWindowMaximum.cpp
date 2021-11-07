//
// Created by BrandonZu on 2021/7/17.
//

#include "common.h"

// Runtime 264ms(>55%) | Memory Usage 132MB(>55%)
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        deque<int> maxQ;
        for(int i = 0; i < nums.size(); i++) {
            if(!maxQ.empty() && maxQ.front() <= i - k)
                maxQ.pop_front();

            while(!maxQ.empty() && nums[maxQ.back()] <= nums[i])
                maxQ.pop_back();

            maxQ.emplace_back(i);
            if(i >= k - 1) {
                result.push_back(nums[maxQ.front()]);
            }
        }
        return result;
    }
};

