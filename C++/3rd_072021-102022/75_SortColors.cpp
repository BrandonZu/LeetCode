//
// Created by BrandonZu on 2021/8/26.
//

#include "common.h"

// Split the array into three parts
// 0: [0 ... zero - 1]
// 1: [zero ... one - 1]
// 2: [two + 1 ... n - 1]

// Runtime 0ms(>100%) | Memory Usage 8.2MB(>92%)
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zero = 0, one = 0, two = nums.size() - 1;
        while(one <= two) {
            if(nums[one] == 1) {
                one++;
            }
            else if(nums[one] == 0) {
                swap(nums[zero], nums[one]);
                zero++;
                one++;
            }
            else {
                swap(nums[two], nums[one]);
                two--;
            }
        }
    }
};
