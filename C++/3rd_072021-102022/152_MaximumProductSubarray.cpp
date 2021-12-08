//
// Created by BrandonZu on 12/7/21.
//

#include "common.h"

// Runtime 3ms(>85%) | Memory Usage 14MB(>7%)
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int res = nums[0];
        int l = 1, r = 1;
        for(int i = 0, j = n - 1; i < n; i++, j--) {
            if(l == 0) l = 1;
            if(r == 0) r = 1;
            l *= nums[i], r *= nums[j];
            res = max(res, max(l, r));
        }
        return res;
    }
};
