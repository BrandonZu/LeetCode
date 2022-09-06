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

// 1st Review 12/12/21
// Runtime 4ms(>98%) | Memory Usage 10MB(>84%)
class Solution_R1 {
public:
    int partition(vector<int>& nums, int l, int r) {
        int pivot = nums[l + r >> 1];
        swap(nums[l], nums[l + r >> 1]);
        while(l < r) {
            while(l < r && nums[r] > pivot)
                r--;
            nums[l] = nums[r];
            while(l < r && nums[l] <= pivot)
                l++;
            nums[r] = nums[l];
        }
        nums[l] = pivot;
        return l;
    }

    int findKthLargest(vector<int>& nums, int k) {
        int l = 0, r = nums.size() - 1;
        while(l < r) {
            int pos = partition(nums, l, r);
            if(r - pos + 1 == k) {
                return nums[pos];
            }
            else if(r - pos + 1 > k) {
                l = pos + 1;
            }
            else {
                k -= (r - pos + 1);
                r = pos - 1;
            }
        }
        return nums[l];
    }
};

// R .12 | M .60
class Solution2 {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int l = 0, r = nums.size() - 1;
        while(l <= r) {
            int p = partition(nums, l, r);
            if(r - p + 1 == k) {
                return nums[p];
            }
            else if(r - p + 1 > k) {
                l = p + 1;
            }
            else {
                k -= (r - p + 1);
                r = p - 1;
            }
        }
        return nums[l];
    }

    int partition(vector<int>& nums, int l, int r) {
        if(l == r) return l;
        int pivot = nums[l];
        int i = l, j = r;
        while(i < j) {
            while(i < j && nums[j] > pivot) {
                j--;
            }
            nums[i] = nums[j];
            while(i < j && nums[i] <= pivot) {
                i++;
            }
            nums[j] = nums[i];
        }
        nums[i] = pivot;
        return i;
    }
};