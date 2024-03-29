//
// Created by BrandonZu on 2021/8/21.
//

#include "common.h"

// Runtime 171ms(>31%) | Memory Usage 83MB(>72%)
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            while(nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i])
                swap(nums[nums[i] - 1], nums[i]);
        }

        for(int i = 0; i < n; i++) {
            if(nums[i] != i + 1)
                return i + 1;
        }
        return n + 1;
    }
};

// 1st Review 11/10/2021
// Runtime 144ms(>84%) | Memory Usage 83MB(>30%)
class Solution_R1 {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            while(nums[i] >= 1 && nums[i] <= n && nums[nums[i] - 1] != nums[i]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        for(int i = 0; i < n; i++) {
            if(nums[i] != i + 1)
                return i + 1;
        }
        return n + 1;
    }
};

