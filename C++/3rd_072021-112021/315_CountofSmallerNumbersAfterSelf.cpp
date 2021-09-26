//
// Created by BrandonZu on 9/25/21.
//

#include "common.h"

// Runtime 136ms(>95%) | Memory Cost 76.1MB(>90%)
class Solution_BIT {
    int n = 20001;
    vector<int> fenwick;
    static inline int lowbit(int x) {
        return x & (-x);
    }

    int query(int i) {
        int res = 0;
        while(i > 0) {
            res += fenwick[i];
            i -= lowbit(i);
        }
        return res;
    }

    void update(int i, int v) {
        while(i < n) {
            fenwick[i] += v;
            i += lowbit(i);
        }
    }

public:
    vector<int> countSmaller(vector<int>& nums) {
        for(int& num: nums) {
            num += 10001;
        }
        vector<int> res(nums.size());
        fenwick.resize(n + 1);
        for(int i = nums.size() - 1; i >= 0; i--) {
            int x = nums[i];
            res[i] = query(x - 1);
            update(x, 1);
        }
        return res;
    }
};

