//
// Created by BrandonZu on 2/8/22.
//

#include "common.h"

// Runtime 20ms(>75%) | Memory Usage MB()
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        if(nums.size() == 1) {
            return nums[0];
        }
        int cur_num = -1, cur_cnt = 0;
        for(int num: nums) {
            if(cur_cnt == 0){
                cur_num = num;
                cur_cnt = 1;
            }
            else if(cur_num == num) {
                cur_cnt++;
            }
            else {
                cur_cnt--;
            }
        }
        return cur_num;
    }
};
