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

// R .100 | M .24
class Solution2 {
public:
    void sortColors(vector<int>& nums) {
        int red = 0, white = 0, blue = nums.size() - 1;
        while(white <= blue) {
            if(nums[white] == 1) {
                ++white;
            }
            else if(nums[white] == 0) {
                swap(nums[white], nums[red]);
                ++red;
                ++white;
            }
            else {
                swap(nums[white], nums[blue]);
                --blue;
            }
        }
    }
};