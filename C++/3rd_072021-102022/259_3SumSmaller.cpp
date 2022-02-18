//
// Created by BrandonZu on 2/18/22.
//

#include "common.h"

// Runtime 52ms(>80%) | Memory Usage 13.4MB(>93%)
class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        if(nums.size() < 3) return false;
        sort(nums.begin(), nums.end());
        int cnt = 0;
        for(int i = 0; i < nums.size() - 2; i++) {
            int l = i + 1, r = nums.size() - 1;
            while(l < r) {
                if(nums[i] + nums[l] + nums[r] < target) {
                    cnt += (r - l);
                    l++;
                }
                else {
                    r--;
                }
            }
        }
        return cnt;
    }
};
