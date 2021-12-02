//
// Created by BrandonZu on 2021/7/26.
//

#include "common.h"

// Runtime 4ms(>80%) | Memory Usage 12MB(>35%)
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.size() <= 1) return;
        int pos = nums.size() - 1;
        while(pos > 0 && nums[pos] <= nums[pos - 1])
            pos--;

        if(pos == 0) {
            reverse(nums.begin(), nums.end());
            return;
        }

        int cur = pos - 1;
        while(pos < nums.size() && nums[pos] > nums[cur])
            pos++;
        swap(nums[cur], nums[pos - 1]);
        reverse(nums.begin() + cur + 1, nums.end());
    }
};

// 1st Review 09/28/21
// Runtime 8ms(>33%) | Memory Usage 12MB(>37%)
class Solution_R1 {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size() - 1;
        while(i - 1 >= 0 && nums[i - 1] >= nums[i])
            i--;
        // Current permutation is the largest
        if(i == 0) {
            sort(nums.begin(), nums.end());
            return;
        }

        int j;
        for(j = i; j < nums.size(); j++) {
            if(nums[j] <= nums[i - 1])
                break;
        }
        swap(nums[i - 1], nums[j - 1]);
        reverse(nums.begin() + i, nums.end());
    }
};
