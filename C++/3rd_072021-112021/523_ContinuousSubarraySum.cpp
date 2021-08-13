//
// Created by BrandonZu on 2021/8/12.
//

#include "common.h"

// Runtime 164ms(>74%) | Memory Usage 100MB(>10%)
class Solution_PrefixSum {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        vector<int> s(nums.size() + 1, 0);
        for(int i = 1; i <= nums.size(); i++) {
            s[i] = s[i - 1] + nums[i - 1];
        }
        unordered_set<int> hash;
        for(int r = 2; r <= nums.size(); r++) {
            hash.insert(s[r - 2] % k);
            if(hash.count(s[r] % k))
                return true;
        }
        return false;
    }
};

// Runtime 152ms(>94%) | Memory Usage 97MB(>51%)
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int sum = 0;
        unordered_map<int, int> hash;
        hash[0] = -1;
        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if(hash.find(sum % k) != hash.end()) {
                int pre = hash[sum % k];
                if(i - pre > 1)
                    return true;
            }
            else
                hash[sum % k] = i;
        }
        return false;
    }
};

