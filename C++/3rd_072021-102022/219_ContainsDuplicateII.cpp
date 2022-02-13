//
// Created by BrandonZu on 2/13/22.
//

#include "common.h"

// Runtime 261ms(>49%) | Memory Usage 77.2MB(>51%)
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> num_cnt;
        for(int r = 0; r < n; r++) {
            num_cnt[nums[r]]++;
            if(r >= k + 1) {
                num_cnt[nums[r - k - 1]]--;
            }
            if(num_cnt[nums[r]] > 1) {
                return true;
            }
        }
        return false;
    }
};
