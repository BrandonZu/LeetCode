//
// Created by BrandonZu on 11/3/21.
//

#include "common.h"

// Runtime 208ms(>53%) | Memory Usage 176MB(>13%)
class SparseVector {
public:
    unordered_set<int> num_set;
    vector<int> num;
    SparseVector(vector<int> &nums) {
        num = nums;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] != 0)
                num_set.insert(i);
        }
    }

    int dotProduct(SparseVector& vec) {
        int ans = 0;
        for(int p: num_set) {
            if(vec.num_set.find(p) != vec.num_set.end()) {
                ans += num[p] * vec.num[p];
            }
        }
        return ans;
    }
};


