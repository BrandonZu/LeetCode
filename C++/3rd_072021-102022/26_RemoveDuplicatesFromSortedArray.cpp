//
// Created by BrandonZu on 2021/7/20.
//

#include "common.h"

// Runtime 8ms (>88%) | Memory Usage 18.4MB(>33%)
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty()) return 0;
        int i = 0;
        for(int j = 1; j < nums.size(); j++) {
            if(nums[j] == nums[j - 1]) {
                int repeat = nums[j - 1];
                while(j < nums.size() && nums[j] == repeat) j++;
                j--;
            }
            else {
                nums[++i] = nums[j];
            }
        }
        return i + 1;
    }
};

// R .91 | M .37
class Solution2 {
public:
    int removeDuplicates(vector<int>& nums) {
        int end = 0;
        int i = 0;
        while(i < nums.size()) {
            nums[end++] = nums[i];
            while(i < nums.size() && nums[end - 1] == nums[i]) {
                i++;
            }
        }
        return end;
    }
};