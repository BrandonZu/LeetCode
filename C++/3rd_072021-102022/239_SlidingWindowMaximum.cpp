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

// 1st Review 11/14/21
// Runtime 240ms(>80%) | Memory Usage 134MB(>38%)
class Solution_R1 {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        deque<pair<int, int>> q;
        for(int i = 0; i < k - 1; i++) {
            while(!q.empty() && q.back().second <= nums[i])
                q.pop_back();
            q.emplace_back(i, nums[i]);
        }
        for(int i = k - 1; i < nums.size(); i++) {
            while(!q.empty() && q.front().first < i - k + 1)
                q.pop_front();
            while(!q.empty() && q.back().second <= nums[i])
                q.pop_back();
            q.emplace_back(i, nums[i]);
            res.push_back(q.front().second);
        }
        return res;
    }
};
