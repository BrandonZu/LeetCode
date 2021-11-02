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

// 1st Review Merge Sort
// Runtime
class Solution_MergeSort {
    vector<pair<int, int>> tmp;
    vector<int> counter;
public:
    void mergeCount(vector<pair<int, int>>& nums, int l, int r) {
        if(l >= r) return;
        int mid = l + r >> 1;

        mergeCount(nums, l, mid);
        mergeCount(nums, mid + 1, r);

        int i = l, j = mid + 1;
        int pos = l;
        while(i <= mid && j <= r) {
            if(nums[i].first > nums[j].first) {
                counter[nums[i].second] += r - j + 1;
                tmp[pos++] = nums[i++];
            }
            else {
                tmp[pos++] = nums[j++];
            }
        }
        while(i <= mid) {
            tmp[pos++] = nums[i++];
        }
        while(j <= r) {
            tmp[pos++] = nums[j++];
        }
        for(int k = l; k <= r; k++) {
            nums[k] = tmp[k];
        }
    }

    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        tmp.resize(n);
        counter.resize(n);
        vector<pair<int, int>> num_index(n);
        for(int i = 0; i < nums.size(); i++) {
            num_index[i].first = nums[i];
            num_index[i].second = i;
        }

        mergeCount(num_index, 0, n - 1);

        return counter;
    }
};

