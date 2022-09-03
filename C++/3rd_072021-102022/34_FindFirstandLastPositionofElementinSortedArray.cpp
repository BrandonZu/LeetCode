//
// Created by BrandonZu on 2021/7/18.
//

#include "common.h"

// Runtime 8ms(>70%) | Memory Usage 13.6MB(>85%)
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result;
        if(nums.empty()) return {-1, -1};
        int l = 0, r = nums.size() - 1;
        // Lower Bound
        while(l < r) {
            int mid = l + r + 1 >> 1;
            if(nums[mid] >= target)
                r = mid;
            else
                l = mid + 1;
        }
        if(nums[l] != target)
            return {-1, -1};
        result.push_back(l);
        // Upper Bound
        l = 0, r = nums.size() - 1;
        while(l < r) {
            int mid = l + r >> 1;
            if(nums[mid] <= target)
                l = mid;
            else
                r = mid - 1;
        }
        result.push_back(r);
        return result;
    }
};

// R .25 | M .84
class Solution2 {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.empty()) return {-1, -1};
        int left = -1, right = -1;
        int l = 0, r = nums.size() - 1;
        // left most
        while(l < r) {
            int mid = (l + r) / 2;
            if(nums[mid] >= target) {
                r = mid;
            }
            else {
                l = mid + 1;
            }
        }
        left = l;
        if(nums[left] != target) {
            return {-1, -1};
        }
        // right most
        l = 0, r = nums.size() - 1;
        while(l < r) {
            int mid = (l + r + 1) / 2;
            if(nums[mid] <= target) {
                l = mid;
            }
            else {
                r = mid - 1;
            }
        }
        right = l;
        return {left, right};
    }
};
