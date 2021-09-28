//
// Created by BrandonZu on 9/26/21.
//

#include "common.h"

// Runtime 4ms(>98%) | Memory Usage 10MB(>59%)
class Solution {
public:
    int partition(vector<int>& nums, int left, int right) {
        int l = left, r = right;
        int pivot = nums[(left + right) / 2];
        swap(nums[left], nums[(left + right) / 2]);
        while(l < r) {
            while(l < r && nums[r] >= pivot)
                r--;
            nums[l] = nums[r];
            while(l < r && nums[l] < pivot)
                l++;
            nums[r] = nums[l];
        }
        nums[l] = pivot;
        return l;
    }

    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 0, r = n - 1;
        while(l < r) {
            int pos = partition(nums, l, r);
            if(r - pos + 1 == k) {
                return nums[pos];
            }
            else if(r - pos + 1 > k) {
                l = pos + 1;
            }
            else {
                k = k - (r - pos + 1);
                r = pos - 1;
            }
        }
        return nums[l];
    }
};

