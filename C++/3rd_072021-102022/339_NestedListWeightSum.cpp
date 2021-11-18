//
// Created by BrandonZu on 11/17/21.
//

#include "common.h"

// Runtime 4ms(>45%) | Memory Usage 8.9MB(>73%)
class Solution {
public:
    int helper(vector<NestedInteger>& nested, int depth) {
        int res = 0;
        for(auto& i: nested) {
            if(i.isInteger()) {
                res += i.getInteger() * depth;
            }
            else {
                res += helper(i.getList(), depth + 1);
            }
        }
        return res;
    }

    int depthSum(vector<NestedInteger>& nestedList) {
        return helper(nestedList, 1);
    }
};

