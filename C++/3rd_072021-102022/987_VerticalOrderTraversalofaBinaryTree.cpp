//
// Created by BrandonZu on 11/4/21.
//

// Runtime 4ms(>80%) | Memory Usage 12.2MB(>95%)
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if(!root) return {};
        unordered_map<int, vector<pair<int, int>>> record;
        queue<pair<pair<int, int>, TreeNode*>> q;
        q.push({{0, 0}, root});
        int min_index = 0, max_index = 0;
        int dept = 0;
        while(!q.empty()) {
            int sz = q.size();
            for(int i = 0; i < sz; i++) {
                auto tmp = q.front();
                q.pop();
                record[tmp.first.second].push_back({tmp.first.first, tmp.second->val});
                if(tmp.second->left) {
                    q.push({{tmp.first.first + 1, tmp.first.second - 1}, tmp.second->left});
                    min_index = min(min_index, tmp.first.second - 1);
                }
                if(tmp.second->right) {
                    q.push({{tmp.first.first + 1, tmp.first.second + 1}, tmp.second->right});
                    max_index = max(max_index, tmp.first.second + 1);
                }
            }
        }

        vector<vector<int>> result;
        for(int i = min_index; i <= max_index; i++) {
            auto& cur = record[i];
            sort(cur.begin(), cur.end());
            vector<int> tmp(cur.size());
            for(int i = 0; i < cur.size(); i++) {
                tmp[i] = cur[i].second;
            }
            result.push_back(tmp);
        }
        return result;
    }
};
