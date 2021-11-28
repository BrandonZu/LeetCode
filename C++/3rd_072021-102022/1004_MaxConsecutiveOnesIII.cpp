//
// Created by BrandonZu on 11/27/21.
//

#include "common.h"

// Runtime 48mb(>91%) | Memory Usage 55MB(>63%)
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int max_len = 0;
        int l = 0, r = 0;
        int cnt = 0;
        while(r < nums.size()) {
            if(nums[r] == 0) {
                cnt++;
            }
            r++;
            while(cnt > k) {
                if(nums[l] == 0)
                    cnt--;
                l++;
            }
            max_len = max(max_len, r - l);
        }
        return max_len;
    }
};
