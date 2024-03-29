//
// Created by BrandonZu on 2021/7/29.
//

#include "common.h"

// Runtime 4ms(>95%) | Memory Usage 10.9MB(>76%)
class Solution_Backtrack {
    vector<vector<int>> result;
    vector<int> path;
public:
    void dfs(const vector<int>& candidates, int pos, int target) {
        for(int i = pos; i < candidates.size(); i++) {
            path.push_back(candidates[i]);

            if(target - candidates[i] > 0)
                dfs(candidates, i, target - candidates[i]);
            else if(target - candidates[i] == 0)
                result.push_back(path);

            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        dfs(candidates, 0, target);
        return result;
    }
};

// 1st Review 2021/8/6
class Solution_Review1 {
    vector<vector<int>> result;
    vector<int> path;
public:
    void backtrack(vector<int>& nums, int start, int target) {
        if(target <= 0) {
            if(target == 0)
                result.push_back(path);
            return;
        }
        for(int i = start; i < nums.size(); i++) {
            path.push_back(nums[i]);
            backtrack(nums, i, target - nums[i]);
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        backtrack(candidates, 0, target);
        return result;
    }
};

// R .70 | M .35
class Solution2 {
    vector<vector<int>> res;
    vector<int> path;
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        helper(candidates, 0, target);
        return res;
    }

    void helper(vector<int>& nums, int pos, int target) {
        if(target <= 0 || pos >= nums.size()) {
            if(target == 0) {
                res.push_back(path);
            }
            return;
        }
        helper(nums, pos + 1, target);
        path.push_back(nums[pos]);
        helper(nums, pos, target - nums[pos]);
        path.pop_back();
    }
};