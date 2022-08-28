//
// Created by BrandonZu on 2021/7/31.
//

#include "common.h"

// Runtime 4ms(>63%) | Memory Usage 7.3MB(>50%)
class Solution_1 {
    vector<vector<int>> result;
    vector<int> path;
public:
    void backtrack(const vector<int>& nums, int pos) {
        result.push_back(path);
        if(pos >= nums.size()) {
            return;
        }

        for(int i = pos; i < nums.size(); i++) {
            path.push_back(nums[i]);
            backtrack(nums, i + 1);
            path.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        backtrack(nums, 0);
        return result;
    }
};

// Runtime 0ms(>100%) | Memory Usage 10.8MB(>27%)
class Solution_2 {
    vector<vector<int>> result;
    vector<int> path;
public:
    void backtrack(const vector<int>& nums, int pos) {
        if(pos >= nums.size()) {
            result.push_back(path);
            return;
        }

        // Neglect nums[i]
        backtrack(nums, pos + 1);
        // Select nums[i]
        path.push_back(nums[pos]);
        backtrack(nums,pos + 1);
        path.pop_back();
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        backtrack(nums, 0);
        return result;
    }
};

// R .100 | M .39
class Solution3_1 {
    vector<vector<int>> res;
    vector<int> path;
public:
    vector<vector<int>> subsets(vector<int> &nums) {
        helper(nums, 0);
        return res;
    }

    void helper(vector<int> &nums, int pos) {
        if(pos >= nums.size()) {
            res.push_back(path);
            return;
        }
        helper(nums, pos + 1);
        path.push_back(nums[pos]);
        helper(nums, pos + 1);
        path.pop_back();
    }
};

// .R 100 | M .71
class Solution3_2 {
    vector<vector<int>> res;
    vector<int> path;
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        backtrack(nums, 0);
        return res;
    }

    void backtrack(vector<int>& nums, int pos) {
        res.push_back(path);
        for(int i = pos; i < nums.size(); i++) {
            path.push_back(nums[i]);
            backtrack(nums, i + 1);
            path.pop_back();
        }
    }
};