//
// Created by BrandonZu on 2021/9/2.
//

#include "common.h"

// Runtime 0ms(>100%) | Memory Cost 11MB(>10%)
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0, j = 0;

        while(j < nums.size()) {
            // Begin Searching
            int num = nums[j];
            int cnt = 0;
            while(j < nums.size() && nums[j] == num) {
                cnt++;
                if(cnt <= 2) {
                    nums[i++] = nums[j];
                }
                j++;
            }
        }

        return i;
    }
};
