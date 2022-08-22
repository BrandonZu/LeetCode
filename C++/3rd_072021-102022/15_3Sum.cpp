//
// Created by BrandonZu on 2021/8/15.
//

#include "common.h"

// Runtime 104ms(>41%) | Memory Usage 20MB(>67%)
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if(nums.size() < 3) return {{}};
        // To use two pointers, array must be ordered
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        // Traverse all possible positions of first pointer
        for(int i = 0; i < nums.size() - 2 && nums[i] <= 0; i++) {
            if(i - 1 > 0 && nums[i] == nums[i - 1])
                continue;
            // Two Pointers
            int l = i + 1, r = nums.size() - 1;
            while(l < r) {
                if(nums[l] + nums[r] + nums[i] == 0) {
                    result.push_back({nums[i], nums[l], nums[r]});
                    l++, r--;
                    while(l < r && nums[l] == nums[l - 1])
                        l++;
                    while(l < r && nums[r] == nums[r + 1])
                        r--;
                }
                else if(nums[l] + nums[r] + nums[i] > 0) {
                    r--;
                    while(l < r && nums[r] == nums[r + 1])
                        r--;
                }
                else {
                    l++;
                    while(l < r && nums[l] == nums[l - 1])
                        l++;
                }
            }
        }
        return result;
    }
};

// R .28 | M .72
class Solution2 {
public:
    inline void moveMid(vector<int>& nums, int& mid, int r) {
        mid++;
        while(nums[mid - 1] == nums[mid] && mid < r) {
            mid++;
        }
    }
    inline void moveR(vector<int>& nums, int mid, int& r) {
        r--;
        while(nums[r] == nums[r + 1] && mid < r) {
            r--;
        }
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for(int l = 0; l < nums.size() - 2; l++) {
            if(l && nums[l] == nums[l - 1]) {
                continue;
            }
            int mid = l + 1, r = nums.size() - 1;
            while(mid < r) {
                if(nums[l] + nums[mid] + nums[r] == 0) {
                    res.push_back({nums[l], nums[mid], nums[r]});
                    moveMid(nums, mid, r);
                    moveR(nums, mid, r);
                }
                else if(nums[l] + nums[mid] + nums[r] > 0) {
                    moveR(nums, mid, r);
                }
                else {
                    moveMid(nums, mid, r);
                }
            }
        }
        return res;
    }
};