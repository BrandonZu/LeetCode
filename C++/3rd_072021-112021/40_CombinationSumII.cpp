//
// Created by BrandonZu on 2021/7/30.
//

#include "common.h"

// Runtime 4ms(>93%) | Memory Usage 10.9MB(>46%)
class Solution {
    vector<vector<int>> result;
    vector<int> path;
    vector<bool> visited;
public:
    void dfs(const vector<int>& candidates, int pos, int target) {
        if(pos >= candidates.size()) return;
        for(int i = pos; i < candidates.size(); i++) {
            // Remove Duplicates
            if(i - 1 >= 0 && candidates[i] == candidates[i - 1] && !visited[i - 1])
                continue;

            path.push_back(candidates[i]);
            visited[i] = true;

            if(target - candidates[i] > 0)
                dfs(candidates, i + 1, target - candidates[i]);
            else if(target - candidates[i] == 0)
                result.push_back(path);

            visited[i] = false;
            path.pop_back();
        }

    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        visited.resize(candidates.size(), false);
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

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        backtrack(candidates, 0, target);
        return result;
    }
};
};