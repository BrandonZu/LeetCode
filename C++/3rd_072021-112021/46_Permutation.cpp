//
// Created by BrandonZu on 2021/7/15.
//

#include "vector"
using namespace std;

// Runtime 0ms(>100%) | Memory Cost 7.7MB(>56%)
class Solution {
    vector<vector<int>> result;
public:
    void dfs(vector<int>& nums, vector<int>& path, vector<bool>& visited, int pos, int size) {
        if(pos == size) {
            result.emplace_back(path);
            return;
        }

        for(int i = 0; i <= size - 1; i++) {
            if(!visited[i]) {
                path[pos] = nums[i];
                visited[i] = true;
                dfs(nums, path, visited, pos + 1, size);
                visited[i] = false;
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        if(nums.empty()) return result;
        vector<bool> visited(nums.size());
        vector<int> path(nums.size());
        dfs(nums, path, visited, 0, nums.size());
        return result;
    }
};

// Runtime 0ms(>100%) | Memory Cost 7.7MB(>56%)
class Review1 {
    vector<vector<int>> result;
    vector<int> path;
    vector<bool> visited;
public:
    void backtrack(const vector<int>& nums) {
        if(path.size() == nums.size()) {
            // Collect result at leaf nodes
            result.push_back(path);
            return;
        }
        for(int i = 0; i < nums.size(); i++) {
            if(visited[i])
                continue;
            path.push_back(nums[i]);
            visited[i] = true;
            backtrack(nums);
            visited[i] = false;
            path.pop_back();
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        visited.resize(nums.size());
        backtrack(nums);
        return result;
    }
};