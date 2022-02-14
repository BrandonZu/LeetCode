//
// Created by BrandonZu on 2/14/22.
//

#include "common.h"

// Runtime 51ms(>52%) | Memory Usage 18.6MB(>46%)
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        int n = nums.size();
        multiset<long> num_set;
        for(int i = 0; i < n; i++) {

            auto p = num_set.lower_bound(nums[i]);
            if(p != num_set.end() && (long)nums[i] + t >= *p) {
                return true;
            }
            if(p != num_set.begin() && (long)nums[i] - t <= *prev(p)) {
                return true;
            }
            num_set.insert(nums[i]);
            if(num_set.size() > k) {
                num_set.erase(nums[i - k]);
            }
        }
        return false;
    }
};
