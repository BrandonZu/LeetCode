//
// Created by BrandonZu on 2021/7/17.
//

#include "common.h"

// Runtime 12ms(>93%) | Memory Usage 13.6MB(>70%)
class Solution {
public:
    struct myCmp {
        bool operator() (const pair<int, int> &a, const pair<int, int> &b) const {
            return a.second > b.second;
        }
    };

    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> result;
        unordered_map<int, int> numCount;
        priority_queue<pair<int, int>, vector<pair<int, int>>, myCmp> pq;
        for(int num: nums)
            numCount[num]++;

        for(auto cnt: numCount) {
            pq.push(cnt);
            if(pq.size() > k)
                pq.pop();
        }
        while(!pq.empty()) {
            result.push_back(pq.top().first);
            pq.pop();
        }
        return result;
    }
};