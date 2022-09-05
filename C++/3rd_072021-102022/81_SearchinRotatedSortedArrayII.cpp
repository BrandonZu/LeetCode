//
// Created by BrandonZu on 2021/7/19.
//

#include "common.h"

// Runtime 0ms(>100%) | Memory Usage 14MB(>90%)
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if(nums.empty())
            return false;
        else if(nums.size() == 1)
            return nums[0] == target;
        int size = nums.size() - 1;
        while(size > 0 && nums[size] == nums[0])
            size--;
        // Find Peak
        int l = 0, r = size;
        while(l < r) {
            int mid = l + r + 1 >> 1;
            if(nums[mid] >= nums[0])
                l = mid;
            else
                r = mid - 1;
        }
        int peak = l;
        if(target >= nums[0])
            l = 0, r = peak;
        else
            l = peak + 1, r = size;

        while(l <= r) {
            int mid = l + r >> 1;
            if(nums[mid] == target)
                return true;
            else if(nums[mid] < target)
                l = mid + 1;
            else
                r = mid - 1;
        }
        return false;
    }
};

// R .42 | M .74
class Solution2 {
public:
    bool search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while(l <= r) {
            int mid = (l + r) / 2;
            if(nums[mid] == target) {
                return true;
            }
            else if(nums[mid] > nums[l]) {
                if(target >= nums[l] && target < nums[mid]) {
                    r = mid - 1;
                }
                else {
                    l = mid + 1;
                }
            }
            else if(nums[mid] < nums[l]) {
                if(target > nums[mid] && target <= nums[r]) {
                    l = mid + 1;
                }
                else {
                    r = mid - 1;
                }
            }
            else {
                if(nums[l] == target) {
                    return true;
                }
                l++;
            }
        }
        return false;
    }
};
