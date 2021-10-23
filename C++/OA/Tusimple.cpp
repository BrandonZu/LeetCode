//
// Created by BrandonZu on 10/22/21.
//

#include "common.h"

// Parking Dilemma

// Distance Metric
vector<long> getDistanceMetrics(vector<long> nums) {
    vector<long> left(nums.size());
    vector<long> right(nums.size());
    vector<long> res(nums.size());
    unordered_map<long, pair<int, int>> num_map;
    for(int i = 0; i < nums.size(); i++) {
        if(num_map.find(nums[i]) == num_map.end()) {
            num_map[nums[i]] = make_pair(i, 1);
            left[i] = 0;
        }
        else {
            left[i] = left[num_map[nums[i]].first] + num_map[nums[i]].second * (i - num_map[nums[i]].first);
            num_map[nums[i]].first = i;
            num_map[nums[i]].second++;
        }
    }

    num_map.clear();
    for(int i = nums.size() - 1; i >= 0; i--) {
        if(num_map.find(nums[i]) == num_map.end()) {
            num_map[nums[i]] = make_pair(i, 1);
            right[i] = 0;
        }
        else {
            right[i] = right[num_map[nums[i]].first] + num_map[nums[i]].second * (num_map[nums[i]].first - i);
            num_map[nums[i]].first = i;
            num_map[nums[i]].second++;
        }
    }

    res[0] = right[0];
    res[nums.size() - 1] = left[nums.size() - 1];
    for(int i = 1; i < nums.size() - 1; i++) {
        res[i] = left[i] + right[i];
    }
    return res;
}

// How many sentences

// Removing Chocolates


int main() {
    vector<long> test = {1, 2, 1, 1, 2, 3};
    vector<long> result = getDistanceMetrics(test);
    return 0;
}
