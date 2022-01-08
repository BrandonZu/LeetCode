//
// Created by BrandonZu on 12/22/21.
//

#include "common.h"

// Runtime 100ms(>77%) | Memory Usage 61MB(>58%)
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        if(nums.size() < 2)
            return -1;
        int slow = nums[0], fast = nums[nums[0]];
        while(slow != fast) {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }

        fast = 0;
        while(fast != slow) {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};
