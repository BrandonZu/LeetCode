//
// Created by BrandonZu on 2021/7/31.
//
#include "common.h"

// Runtime 49ms(>80%) | Memory Usage 19.8MB(>96%)
class Solution {
    vector<vector<int>> result;
    vector<int> path;
public:
    void backtrack(const vector<int>& nums, int pos) {
        if(path.size() >= 2)
            result.push_back(path);
        if(pos >= nums.size())
            return;

        // Avoid duplicate elements in the same level
        int visited[220] = {};

        for(int i = pos; i < nums.size(); i++) {
            // Keep monotonically increasing
            if(!path.empty() && nums[i] < path.back())
                continue;
            // Avoid repetitive results
            if(visited[nums[i] + 100])
                continue;

            path.push_back(nums[i]);
            visited[nums[i] + 100] = true;
            backtrack(nums, i + 1);
            path.pop_back();
        }
    }

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        backtrack(nums, 0);
        return result;
    }
};
