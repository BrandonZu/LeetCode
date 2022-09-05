//
// Created by BrandonZu on 2021/9/2.
//

#include "common.h"

// Runtime 0ms(>100%) | Memory Cost 11MB(>10%)
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0, j = 0;

        while(j < nums.size()) {
            // Begin Searching
            int num = nums[j];
            int cnt = 0;
            while(j < nums.size() && nums[j] == num) {
                cnt++;
                if(cnt <= 2) {
                    nums[i++] = nums[j];
                }
                j++;
            }
        }

        return i;
    }
};

// 1st Review
// Runtime 4ms(>84%) | Memory Usage 11MB(>75%)
class Solution_R1 {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = 0;
        while(j < n) {
            int tmp;
            for(tmp = j; tmp < n && nums[tmp] == nums[j]; tmp++) {
                if(tmp - j < 2)
                    nums[i++] = nums[j];
            }
            j = tmp;
        }
        return i;
    }
};

// R .75 | M .41
class Solution2 {
public:
    int removeDuplicates(vector<int>& nums) {
        int end = 0;
        int i = 0;
        while(i < nums.size()) {
            int curVal = nums[i];
            nums[end++] = nums[i++];
            if(i < nums.size() && nums[i] == curVal) {
                nums[end++] = nums[i++];
            }
            while(i < nums.size() && nums[i] == curVal) {
                i++;
            }
        }
        return end;
    }
};