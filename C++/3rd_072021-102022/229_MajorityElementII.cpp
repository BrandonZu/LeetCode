//
// Created by BrandonZu on 2/16/22.
//

#include "common.h"

// Runtime 20ms(>45%) | Memory Usage 15.9MB(>20%)
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> res;
        int num1, num2;
        int cnt1 = 0, cnt2 = 0;
        for(int num: nums) {
            if(num == num1) {
                cnt1++;
            }
            else if(num == num2) {
                cnt2++;
            }
            else if(cnt1 == 0) {
                num1 = num;
                cnt1 = 1;
            }
            else if(cnt2 == 0) {
                num2 = num;
                cnt2 = 1;
            }
            else {
                cnt1--, cnt2--;
            }
        }
        int tmp1 = 0, tmp2 = 0;
        for(int num: nums) {
            if(num == num1) {
                tmp1++;
            }
            else if(num == num2) {
                tmp2++;
            }
        }
        if(tmp1 > nums.size() / 3)
            res.push_back(num1);
        if(tmp2 > nums.size() / 3)
            res.push_back(num2);
        return res;
    }
};
