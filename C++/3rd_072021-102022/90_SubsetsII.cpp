//
// Created by BrandonZu on 2021/7/31.
//

#include "common.h"

// Runtime 4ms(>76%) | Memory Usage 7.8MB(>52.38%)
class Solution {
    vector<vector<int>> result;
    vector<int> path;
    vector<bool> visited;
public:
    void backtrack(const vector<int>& nums, int pos) {
        result.push_back(path);
        if(pos >= nums.size()) {
            return;
        }

        for(int i = pos; i < nums.size(); i++) {
            if(i > 0 && nums[i - 1] == nums[i] && !visited[i - 1])
                continue;
            path.push_back(nums[i]);
            visited[i] = true;
            backtrack(nums, i + 1);
            visited[i] = false;
            path.pop_back();
        }

    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        visited.resize(nums.size(), false);
        backtrack(nums, 0);
        return result;
    }
};