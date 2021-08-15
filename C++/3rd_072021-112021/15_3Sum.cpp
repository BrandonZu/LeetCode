//
// Created by BrandonZu on 2021/8/15.
//

#include "common.h"

// Runtime 104ms(>41%) | Memory Usage 20MB(>67%)
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if(nums.size() < 3) return {{}};
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        int i = 0;
        while(i < nums.size() - 2 && nums[i] <= 0) {
            int l = i + 1, r = nums.size() - 1;
            while(l < r) {
                if(nums[l] + nums[r] + nums[i] == 0) {
                    result.push_back({nums[i], nums[l], nums[r]});
                    l++;
                    while(l < r && nums[l] == nums[l - 1])
                        l++;
                    r--;
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
            i++;
            while(i < nums.size() && nums[i] == nums[i - 1])
                i++;
        }
        return result;
    }
};
