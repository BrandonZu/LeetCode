//
// Created by BrandonZu on 11/27/21.
//

#include "common.h"

// Runtime 4ms(>83%) | Memory Usage 9.5MB(>67%)
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int prev = 0;
        for(int i: arr) {
            int missing = i - prev - 1;
            if(k > missing) {
                k -= missing;
            }
            else {
                return prev + k;
            }
            prev = i;
        }
        return arr.back() + k;
    }
};
