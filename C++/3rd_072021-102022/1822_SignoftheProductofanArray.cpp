//
// Created by BrandonZu on 9/30/21.
//

#include "common.h"

// Runtime 8ms(>51%) | Memory Usage 10MB(>88%)
class Solution {
public:
    int arraySign(vector<int>& nums) {
        bool flag = true;
        for(int num: nums) {
            if(num == 0)
                return 0;
            else if(num < 0)
                flag = !flag;
        }
        return flag == true ? 1 : -1;
    }
};
