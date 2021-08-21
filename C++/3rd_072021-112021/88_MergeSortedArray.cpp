//
// Created by BrandonZu on 2021/8/20.
//

#include "common.h"

// Runtime 4ms(>51%) | Memory Usage 9.2MB(>30%)
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1, j = n - 1;
        int pos = m + n - 1;
        while(i >= 0 && j >= 0) {
            if(nums1[i] > nums2[j]) {
                nums1[pos] = nums1[i];
                i--;
            }
            else {
                nums1[pos] = nums2[j];
                j--;
            }
            pos--;
        }

        while(j >= 0) {
            nums1[pos] = nums2[j];
            j--;
            pos--;
        }
    }
};

