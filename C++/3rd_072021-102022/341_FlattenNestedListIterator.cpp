//
// Created by BrandonZu on 12/10/21.
//

#include "common.h"

// Runtime 16ms(>63%) | Memory Usage 14.3MB(>44%)
class NestedIterator {
    int pos = 0;
    vector<int> nums;
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        recur(nestedList);
    }

    void recur(const vector<NestedInteger>& nodeList) {
        for(auto p: nodeList) {
            if(p.isInteger()) {
                nums.push_back(p.getInteger());
            }
            else {
                recur(p.getList());
            }
        }
    }

    int next() {
        return nums[pos++];
    }

    bool hasNext() {
        return pos < nums.size();
    }
};
