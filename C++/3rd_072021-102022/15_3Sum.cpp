//
// Created by BrandonZu on 2021/8/15.
//

#include "common.h"

// Runtime 104ms(>41%) | Memory Usage 20MB(>67%)
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if(nums.size() < 3) return {{}};
        // To use two pointers, array must be ordered
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        // Traverse all possible positions of first pointer
        for(int i = 0; i < nums.size() - 2 && nums[i] <= 0; i++) {
            if(i - 1 > 0 && nums[i] == nums[i - 1])
                continue;
            // Two Pointers
            int l = i + 1, r = nums.size() - 1;
            while(l < r) {
                if(nums[l] + nums[r] + nums[i] == 0) {
                    result.push_back({nums[i], nums[l], nums[r]});
                    l++, r--;
                    while(l < r && nums[l] == nums[l - 1])
                        l++;
                    while(l < r && nums[r] == nums[r + 1])
                        r--;
                }
                else if(nums[l] + nums[r] + nums[i] > 0) {
                    r--;
                    while(l < r && nums[r] == nums[r + 1])
                        r--;
                }
                else {
                    l++;
                    while(l < r && nums[l] == nums[l - 1])
                        l++;
                }
            }
        }
        return result;
    }
};
