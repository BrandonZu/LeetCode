//
// Created by BrandonZu on 2021/7/20.
//

#include "common.h"

// Runtime 0ms(>100%) | Memory Usage 8.6MB(>95%)
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = -1, j;
        for(j = 0; j < nums.size(); j++) {
            if(nums[j] == val)
                continue;
            else
                nums[++i] = nums[j];
        }

        return i + 1;
    }
};

// Runtime 3ms(>69%) | Memory Usage 8.8MB(>73%)
class Solution2 {
public:
    int removeElement(vector<int>& nums, int val) {
        int last = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] != val) {
                nums[last++] = nums[i];
            }
        }
        return last;
    }
};