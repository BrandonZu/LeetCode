//
// Created by BrandonZu on 11/27/21.
//

#include "common.h"

// Runtime 310ms(>38%) | Memory Usage 108MB(>32%)
class RandomizedCollection {
    unordered_map<int, unordered_set<int>> numToIndexes;
    vector<int> nums;
public:
    RandomizedCollection() {}

    bool insert(int val) {
        bool notExist = numToIndexes.find(val) == numToIndexes.end() || numToIndexes[val].size() == 0;
        nums.push_back(val);
        numToIndexes[val].insert(nums.size() - 1);
        return notExist;
    }

    bool remove(int val) {
        bool exist = numToIndexes.find(val) != numToIndexes.end() && numToIndexes[val].size() != 0;
        if(!exist) return exist;
        if(nums.back() == val) {
            numToIndexes[val].erase(nums.size() - 1);
            nums.pop_back();
        }
        else {
            int pos = *numToIndexes[val].begin();
            numToIndexes[nums.back()].erase(nums.size() - 1);
            numToIndexes[nums.back()].insert(pos);
            swap(nums[pos], nums.back());
            numToIndexes[val].erase(pos);
            nums.pop_back();
        }
        return exist;
    }

    int getRandom() {
        return nums[rand() % nums.size()];
    }
};
