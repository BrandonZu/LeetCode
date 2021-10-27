//
// Created by BrandonZu on 10/25/21.
//

#include "common.h"

// Number of Inversions

int inversionNumber(vector<int> nums) {
    int n = nums.size();
    vector<int> pre_num(n, 0);
    vector<int> suf_num(n, 0);
    for(int i = 0; i < nums.size(); i++) {
        int tmp = 0;
        for(int j = i - 1; j >= 0; j--) {
            if(nums[j] > nums[i])

        }
    }
    for(int i = nums.size() - 1; i >= 0; i--) {

    }
    int res = 0;
    for(int i = 0; i < nums.size(); i++) {
        res += pre_num[i] * suf_num[i];
    }
    return res;
}

int main() {
    vector<int> nums = {5, 3, 4, 2, 1};
    cout << inversionNumber(nums) << endl;
}
