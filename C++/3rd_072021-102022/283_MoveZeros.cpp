//
// Created by BrandonZu on 2/28/22.
//

#include "common.h"

// Runtime 32ms(>59%) | Memory Usage 19.3MB(>59%)
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        if(n <= 1) return;
        int l = -1, r = -1;
        for(int i = 0; i < n; i++) {
            if(l == -1 && r == -1) {
                if(nums[i] == 0)
                    l = i, r = i;
                continue;
            }

            if(nums[i] == 0) {
                r++;
            }
            else {
                swap(nums[i], nums[l]);
                l++, r++;
            }
        }
    }
};
