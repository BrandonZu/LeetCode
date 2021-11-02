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

// 1st Review 01/11/21
// Runtime 16ms(>74%) | Memory Usage 14MB(>90%)
class Solution_R1 {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> num_map;
        for(int num: nums) {
            num_map[num]++;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        for(auto p: num_map) {
            if(pq.size() < k) {
                pq.push({p.second, p.first});
            }
            else {
                if(pq.top().first < p.second) {
                    pq.pop();
                    pq.push({p.second, p.first});
                }
            }
        }
        vector<int> result;
        while(!pq.empty()) {
            result.push_back(pq.top().second);
            pq.pop();
        }
        return result;
    }
};