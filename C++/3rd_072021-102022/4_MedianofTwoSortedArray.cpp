//
// Created by BrandonZu on 2021/7/19.
//

#include "common.h"

// R .96 | M .63
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int total = nums1.size() + nums2.size();
        if(total % 2 == 0) {
            int left = findKthElement(nums1, 0, nums2, 0, total / 2);
            int right = findKthElement(nums1, 0, nums2, 0, total / 2 + 1);
            return (left + right) / 2.0;
        }
        else {
            return findKthElement(nums1, 0, nums2, 0, (total + 1) / 2);
        }
        return 0;
    }

    int findKthElement(vector<int>& nums1, int i, vector<int>& nums2, int j, int k) {
        // Make nums1 shorter than nums2
        if(nums1.size() - i > nums2.size() - j) return findKthElement(nums2, j, nums1, i, k);
        // Base Case
        if(k == 1) {
            if(i == nums1.size()) return nums2[j];
            return min(nums1[i], nums2[j]);
        }
        if(i == nums1.size()) return nums2[j + k - 1];

        int si = min((int)nums1.size(), i + k / 2), sj = j + (k - k / 2);
        if(nums1[si - 1] > nums2[sj - 1]) {
            return findKthElement(nums1, i, nums2, sj, k - (sj - j));
        }
        else {
            return findKthElement(nums1, si, nums2, j, k - (si - i));
        }
    }
};
