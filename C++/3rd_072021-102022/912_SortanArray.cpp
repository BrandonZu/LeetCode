//
// Created by BrandonZu on 9/4/22.
//

#include "common.h"

// R . | M .
class Solution {
public:
    vector<int> tmp;

    vector<int> sortArray(vector<int>& nums) {
        quickSort(nums, 0, nums.size() - 1);
        return nums;
    }

    void quickSort(vector<int>& nums, int l, int r) {
        if(l >= r) {
            return;
        }
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
        quickSort(nums, l, i);
        quickSort(nums, i + 1, r);
    }

    void mergeSort(vector<int>& nums, int l, int r) {
        if(l >= r) {
            return;
        }

        int mid = (l + r) / 2;
        mergeSort(nums, l, mid);
        mergeSort(nums, mid + 1, r);
        int i = l, j = mid + 1;
        int pos = l;
        while(i <= mid && j <= r) {
            if(nums[i] < nums[j]) {
                tmp[pos++] = nums[i++];
            }
            else {
                tmp[pos++] = nums[j++];
            }
        }
        while(i <= mid) {
            tmp[pos++] = nums[i++];
        }
        while(j <= r) {
            tmp[pos++] = nums[j++];
        }
        for(int t = l; t <= r; t++) {
            nums[t] = tmp[t];
        }
    }
};
