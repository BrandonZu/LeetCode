//
// Created by BrandonZu on 10/26/21.
//
#include "common.h"
using namespace std;

int find_mistake(int *nums, int nums_length) {
    vector<int> used(nums_length + 1);
    int res = 0;
    for(int i = 1; i <= nums_length; i++) {
        if(used[nums[i - 1]] != -1) {
            res += nums[i];
        }
        used[i] = nums[i];
    }
    for(int i = 1; i <= nums_length; i++) {
        if(used[i] == -1)
            res += i;
    }
    return res;
}


int almost_palindrome(string str) {
    int cnt = 0;
    for(int i = 0, j = (int)str.size() - 1; i < str.size(); i++, j--) {
        if(str[i] != str[j]) {
            cnt++;
        }
    }
    return cnt;
}

bool can_reach_end(int *nums, int nums_length) {
    int max_reach = 0;
    for(int i = 0; i < nums_length; i++) {
        if(max_reach >= nums_length - 1)
            return true;
        if(i > max_reach)
            return false;
        max_reach = max(max_reach, nums[i] + i);
    }
    return max_reach >= nums_length - 1;
}
