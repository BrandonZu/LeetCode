//
// Created by BrandonZu on 2021/8/8.
//

#include "common.h"

// Runtime 4ms(>75%) | Memory Usage 9.6MB(>50%)
class Solution {
public:
    bool findNum(const vector<int>& nums, int t) {
        int l = 0, r = nums.size() - 1;
        while(l <= r) {
            int mid = l + r >> 1;
            if(nums[mid] == t)
                return true;
            else if(nums[mid] > t)
                r = mid - 1;
            else
                l = mid + 1;
        }
        return false;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty())
            return false;
        int l = 0, r = matrix.size() - 1, len = matrix[0].size();
        while(l <= r) {
            int mid = l + r >> 1;
            if(matrix[mid][0] <= target && target <= matrix[mid][len - 1])
                return findNum(matrix[mid], target);
            else if(matrix[mid][0] >= target)
                r = mid - 1;
            else
                l = mid + 1;
        }
        return false;
    }
};
