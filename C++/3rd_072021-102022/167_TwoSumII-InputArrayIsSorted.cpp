//
// Created by BrandonZu on 1/11/22.
//

#include "common.h"

// Runtime 4ms(>88%) | Memory Usage 9.7MB(>44%)
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0, r = numbers.size() - 1;
        while(l < r) {
            if(numbers[l] + numbers[r] == target) {
                return {l + 1, r + 1};
            }
            else if(numbers[l] + numbers[r] > target) {
                r--;
            }
            else {
                l++;
            }
        }
        return {};
    }
};
