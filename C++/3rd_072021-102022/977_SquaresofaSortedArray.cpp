//
// Created by BrandonZu on 11/27/21.
//

#include "common.h"

// Runtime 16ms(>100%) | Memory Usage 27MB(>32%)
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n - 1;
        while(l < r) {
            int mid = l + r >> 1;
            if(nums[mid] >= 0) {
                r = mid;
            }
            else {
                l = mid + 1;
            }
        }
        r = l, l = l - 1;
        vector<int> res;
        while(l >= 0 && r < n) {
            if(nums[r] > -nums[l]) {
                res.push_back(nums[l] * nums[l]);
                l--;
            }
            else {
                res.push_back(nums[r] * nums[r]);
                r++;
            }
        }
        while(l >= 0) {
            res.push_back(nums[l] * nums[l]);
            l--;
        }
        while(r < n) {
            res.push_back(nums[r] * nums[r]);
            r++;
        }
        return res;
    }
};

// Runtime 40ms(>84%) | Memoru Usage 26MB(>31%)
class Solution2 {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> res;
        int l = 0, r = nums.size() - 1;
        while(l <= r) {
            if(pow(nums[l], 2) > pow(nums[r], 2)) {
                res.push_back(pow(nums[l++], 2));
            }
            else {
                res.push_back(pow(nums[r--], 2));
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};