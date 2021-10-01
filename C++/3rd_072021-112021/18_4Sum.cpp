//
// Created by BrandonZu on 9/30/21.
//

#include "common.h"

// Runtime 208ms(>24%) | Memory Usage 13MB(>83%)
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for(int a = 0; a + 3 < nums.size(); a++) {
            if(a > 0 && nums[a] == nums[a - 1])
                continue;
            for(int b = a + 1; b + 2 < nums.size(); b++) {
                if(b > a + 1 && nums[b - 1] == nums[b])
                    continue;
                int c = b + 1, d = nums.size() - 1;
                while(c < d) {
                    // Avoid Overflow
                    if((long)nums[c] + nums[d] + nums[a] + nums[b] == target) {
                        res.push_back({nums[a], nums[b], nums[c], nums[d]});
                        c++, d--;
                        while(c < d && nums[c - 1] == nums[c]) c++;
                        while(c < d && nums[d + 1] == nums[d]) d--;
                    }
                    else if((long)nums[c] + nums[d] + nums[a] + nums[b] > target) {
                        d--;
                        while(c < d && nums[d + 1] == nums[d]) d--;
                    }
                    else {
                        c++;
                        while(c < d && nums[c - 1] == nums[c]) c++;
                    }
                }
            }
        }
        return res;
    }
};
