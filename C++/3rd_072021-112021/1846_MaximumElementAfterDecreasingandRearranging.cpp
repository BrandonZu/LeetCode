//
// Created by BrandonZu on 10/24/21.
//

#include "common.h"

class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int pre = 0;
        for(int a: arr) {
            pre = min(pre + 1, a);
        }
        return pre;
    }
};
