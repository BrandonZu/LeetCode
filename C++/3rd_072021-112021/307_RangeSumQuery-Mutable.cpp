//
// Created by BrandonZu on 9/25/21.
//

#include "common.h"

// Runtime 368ms(>90%) | Memory Usage 150MB(>98%)
class NumArray {
    vector<int> preSum;
    static inline int lowbit(int x) {
        return x & (-x);
    }

    void treeUpdate(int index, int delta) {
        while(index < preSum.size()) {
            preSum[index] += delta;
            index += lowbit(index);
        }
    }

    int treeQuery(int index) {
        int sum = 0;
        while(index > 0) {
            sum += preSum[index];
            index -= lowbit(index);
        }
        return sum;
    }
    vector<int> nums_;
public:
    NumArray(vector<int>& nums): nums_(move(nums)) {
        preSum.resize(nums_.size() + 1, 0);
        for(int i = 0; i < nums_.size(); i++) {
            treeUpdate(i + 1, nums_[i]);
        }
    }

    void update(int index, int val) {
        treeUpdate(index + 1, val - nums_[index]);
        nums_[index] = val;
    }

    int sumRange(int left, int right) {
        return treeQuery(right + 1) - treeQuery(left);
    }
};

int main() {
    vector<int> tmp = {1, 3, 5};
    NumArray test(tmp);
    cout << test.sumRange(0, 2);
    test.update(1, 2);
    cout << test.sumRange(0, 2);
}
