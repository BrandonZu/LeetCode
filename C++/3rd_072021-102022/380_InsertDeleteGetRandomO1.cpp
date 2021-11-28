//
// Created by BrandonZu on 11/27/21.
//

#include "common.h"

// Runtime 208ms(>86%) | Memory Usage 97MB(>80%)
class RandomizedSet {
    unordered_map<int, int> numToIndex;
    vector<int> nums;
public:
    RandomizedSet() {

    }

    bool insert(int val) {
        if(numToIndex.find(val) == numToIndex.end()) {
            nums.push_back(val);
            numToIndex[val] = nums.size() - 1;
            return true;
        }
        else {
            return false;
        }
    }

    bool remove(int val) {
        if(numToIndex.find(val) == numToIndex.end()) {
            return false;
        }
        int pos = numToIndex[val];
        swap(nums[pos], nums.back());
        numToIndex[nums[pos]] = pos;

        numToIndex.erase(val);
        nums.pop_back();
        return true;
    }

    int getRandom() {
        return nums[rand() % nums.size()];
    }
};
