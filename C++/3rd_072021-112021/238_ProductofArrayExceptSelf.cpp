//
// Created by BrandonZu on 2021/8/18.
//

#include "common.h"

// Runtime 24ms(>57%) | Memory Usage 24MB(>81%)
class Solution_1 {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // Prefix and Suffix
        vector<int> res(nums.size(), 1);
        // Prefix
        for(int i = 1; i < nums.size(); i++) {
            res[i] = res[i - 1] * nums[i - 1];
        }
        // Suffix
        int product = 1;
        for(int i = nums.size() - 2; i >= 0; i--) {
            product *= nums[i + 1];
            res[i] *= product;
        }
        return res;
    }
};

// Runtime 4ms(>100%) | Memory Usage 24MB(>93%)
class Solution_2 {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int product = 1, zero_cnt = 0, zero_pos = -1;
        vector<int> res(nums.size(), 0);
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == 0) {
                zero_cnt++;
                zero_pos = i;
            }
            else {
                product *= nums[i];
            }
        }
        if(zero_cnt >= 2) {
            return res;
        }
        if(zero_cnt == 1) {
            res[zero_pos] = product;
            return res;
        }
        for(int i = 0; i < res.size(); i++) {
            res[i] = product / nums[i];
        }
        return res;
    }
};

