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

// 2nd Review 10/17/21
// Runtime 4ms(>70%) | Memory Cost 7.9MB(>40%)
class Solution_R2 {
    vector<vector<int>> result;
    vector<int> cur_path;
    vector<bool> used_dict;
public:
    void recur(vector<int>& nums, int pos, int n) {
        if(pos == n) {
            result.push_back(cur_path);
            return;
        }
        for(int i = 0; i < used_dict.size(); i++) {
            if(used_dict[i] == false) {
                cur_path.push_back(nums[i]);
                used_dict[i] = true;
                recur(nums, pos + 1, n);
                used_dict[i] = false;
                cur_path.pop_back();
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        used_dict.resize(nums.size(), false);
        recur(nums, 0, nums.size());
        return result;
    }
};

// R .100 | M .45
class Solution3 {
    vector<vector<int>> result;
    vector<int> path;
    vector<bool> visited;
public:
    vector<vector<int>> permute(vector<int>& nums) {
        visited.resize(nums.size(), false);
        backtrack(nums);
        return result;
    }

    void backtrack(vector<int>& nums) {
        if(path.size() == nums.size()) {
            result.push_back(path);
            return;
        }
        for(int i = 0; i < nums.size(); i++) {
            if(visited[i]) {
                continue;
            }
            visited[i] = true;
            path.push_back(nums[i]);
            backtrack(nums);
            path.pop_back();
            visited[i] = false;
        }
    }
};