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

// R .49 | M .26
class Solution2 {
    vector<vector<int>> res;
    vector<int> path;
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        helper(nums, 0);
        return res;
    }

    void helper(vector<int>& nums, int pos) {
        if(pos >= nums.size()) {
            res.push_back(path);
            return;
        }
        int end = pos + 1;
        while(end < nums.size() && nums[end] == nums[pos]) {
            end++;
        }
        end--;
        helper(nums, end + 1);
        for(int i = 0; i < end - pos + 1; i++) {
            path.push_back(nums[pos]);
            helper(nums, end + 1);
        }
        path.resize(path.size() - (end - pos + 1));
    }
};