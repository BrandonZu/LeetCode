//
// Created by BrandonZu on 11/27/21.
//

#include "common.h"

// Runtime 56ms(>36%) | Memory Usage 34.7MB(>96%)
class Solution_ReservoirSampling {
public:
    vector<int> nums;

    Solution_ReservoirSampling(vector<int>& nums) {
        this->nums.swap(nums);
    }

    int pick(int target) {
        int cnt = 0;
        int idx = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == target) {
                cnt++;
                if(rand() % cnt == 0) {
                    idx = i;
                }
            }
        }
        return idx;
    }
};

// Runtime 132ms(>36%) | Memory Usage 52MB(>60%)
class Solution {
    unordered_map<int, pair<int, vector<int>>> numToIndex;
public:
    Solution(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++) {
            if(numToIndex.find(nums[i]) == numToIndex.end()) {
                numToIndex[nums[i]].first = 0;
            }
            numToIndex[nums[i]].second.push_back(i);
        }
    }

    int pick(int target) {
        int ret = numToIndex[target].second[numToIndex[target].first];
        numToIndex[target].first = (numToIndex[target].first + 1) % numToIndex[target].second.size();
        return ret;
    }
};


