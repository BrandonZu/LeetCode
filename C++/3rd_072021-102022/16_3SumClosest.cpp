//
// Created by BrandonZu on 2021/8/17.
//

#include "common.h"

// Runtime 12ms(>52%) | Memory Usage 9.9MB(>13%)
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int diff = INT_MAX, flag = 1;
        for(int i = 0; i < nums.size() - 2; i++) {
            int l = i + 1, r = nums.size() - 1;
            while(l < r) {
                if(nums[i] + nums[l] + nums[r] == target) {
                    return target;
                }
                else if(nums[i] + nums[l] + nums[r] > target) {
                    if(nums[i] + nums[l] + nums[r] - target < diff) {
                        diff = nums[i] + nums[l] + nums[r] - target;
                        flag = 1;
                    }
                    r--;
                }
                else {
                    if(target - (nums[i] + nums[l] + nums[r]) < diff) {
                        diff = target - (nums[i] + nums[l] + nums[r]);
                        flag = -1;
                    }
                    l++;
                }
            }
        }
        return target + diff * flag;
    }
};
