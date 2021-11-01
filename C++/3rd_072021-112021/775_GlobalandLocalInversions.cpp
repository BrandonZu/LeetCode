//
// Created by BrandonZu on 10/31/21.
//

#include "common.h"

// Runtime 212ms(>33%) | Memory Usage 87MB(>10%)
class Solution {
    int local = 0, global = 0;
public:
    vector<int> tmp;

    void mergeCount(vector<int>& nums, int l, int r) {
        if(l >= r || global > local) return;
        int mid = l + r >> 1;

        mergeCount(nums, l, mid);
        mergeCount(nums, mid + 1, r);
        int i = l, j = mid + 1;
        int pos = l;
        while(i <= mid && j <= r) {
            if(nums[i] <= nums[j]) {
                tmp[pos++] = nums[i++];
            }
            else {
                global += mid - i + 1;
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

    bool isIdealPermutation(vector<int>& nums) {
        for(int i = 0; i <= (int)nums.size() - 2; i++) {
            if(nums[i] > nums[i + 1])
                local++;
        }
        tmp.resize(nums.size());

        mergeCount(nums, 0, nums.size() - 1);

        return local == global;
    }
};

// Runtime 112ms(98%) | Memory Usage 83.4MB(>36%)
class Solution_Optimized {
public:
    bool isIdealPermutation(vector<int>& nums) {
        int cur_max = nums[0];
        for(int i = 0; i + 2 < nums.size(); i++) {
            cur_max = max(cur_max, nums[i]);
            if(cur_max > nums[i + 2])
                return false;
        }
        return true;
    }
};
