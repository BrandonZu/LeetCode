//
// Created by BrandonZu on 2021/7/29.
//

#include "common.h"

// Runtime 4ms(>95%) | Memory Usage 10.9MB(>76%)
class Solution {
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
