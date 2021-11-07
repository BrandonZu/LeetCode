//
// Created by BrandonZu on 11/4/21.
//

#include "common.h"
#include "TreeNode.h"

// Runtime 4ms(>80%) | Memory Usage 12.2MB(>95%)
class Solution {
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        if(!root) return {};
        unordered_map<int, vector<int>> record;
        queue<pair<int, TreeNode*>> q;
        q.push({0, root});
        int min_index = 0, max_index = 0;
        while(!q.empty()) {
            int sz = q.size();
            for(int i = 0; i < sz; i++) {
                auto tmp = q.front();
                q.pop();
                record[tmp.first].push_back(tmp.second->val);
                if(tmp.second->left) {
                    q.push({tmp.first - 1, tmp.second->left});
                    min_index = min(min_index, tmp.first - 1);
                }
                if(tmp.second->right) {
                    q.push({tmp.first + 1, tmp.second->right});
                    max_index = max(max_index, tmp.first + 1);
                }
            }
        }

        vector<vector<int>> result;
        for(int i = min_index; i <= max_index; i++) {
            result.push_back(record[i]);
        }
        return result;
    }
};