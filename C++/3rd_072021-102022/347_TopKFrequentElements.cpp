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

// R .64 | M .73
class Solution2 {
public:
    unordered_map<int, int> numCnt;
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> newNums;
        for(int num : nums) {
            if(numCnt[num] == 0) {
                newNums.push_back(num);
            }
            numCnt[num]++;
        }
        int l = 0, r = newNums.size() - 1;
        while(l <= r) {
            int pos = partition(newNums, l, r);
            if(r - pos + 1 == k) {
                return {newNums.begin() + pos, newNums.end()};
            }
            else if(r - pos + 1 > k) {
                l = pos + 1;
            }
            else {
                k -= (r - pos + 1);
                r = pos - 1;
            }
        }
        return {};
    }

    int partition(vector<int>& nums, int l, int r) {
        if(l == r) return l;
        int pivot = nums[l];
        while(l < r) {
            while(l < r && numCnt[nums[r]] > numCnt[pivot]) {
                r--;
            }
            nums[l] = nums[r];
            while(l < r && numCnt[nums[l]] <= numCnt[pivot]) {
                l++;
            }
            nums[r] = nums[l];
        }
        nums[l] = pivot;
        return l;
    }
};