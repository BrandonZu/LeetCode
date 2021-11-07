//
// Created by BrandonZu on 2021/7/27.
//

#include "common.h"

// Runtime 8ms(>72%) | Memory Usage 8.8MB(>75%)
class Solution {
    vector<bool> visited;
    vector<vector<int>> result;
    vector<int> path;
public:
    void dfs(vector<int>& nums, int pos) {
        if(pos == nums.size()) {
            result.push_back(path);
            return;
        }

        for(int i = 0; i < nums.size(); i++) {
            if(!visited[i]) {
                if(i > 0 && nums[i] == nums[i - 1] && !visited[i - 1])
                    continue;
                path[pos] = nums[i];
                visited[i] = true;
                dfs(nums, pos + 1);
                visited[i] = false;
            }
        }

    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        if(nums.empty()) return result;
        visited.resize(nums.size(), false);
        path.resize(nums.size());
        sort(nums.begin(), nums.end());
        dfs(nums, 0);
        return result;
    }
};

// Runtime 8ms(>72%) | Memory Usage 8.8MB(>75%)
class Review1 {
    vector<vector<int>> result;
    vector<int> path;
    vector<bool> visited;
public:
    void backtrack(const vector<int>& nums) {
        if(path.size() == nums.size())  {
            result.push_back(path);
            return;
        }

        for(int i = 0; i < nums.size(); i++) {
            if(visited[i]) continue;
            if(i > 0 && nums[i - 1] == nums[i] && !visited[i - 1]) continue;
            path.push_back(nums[i]);
            visited[i] = true;
            backtrack(nums);
            visited[i] = false;
            path.pop_back();
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        visited.resize(nums.size(), false);
        sort(nums.begin(), nums.end());
        backtrack(nums);
        return result;
    }
};