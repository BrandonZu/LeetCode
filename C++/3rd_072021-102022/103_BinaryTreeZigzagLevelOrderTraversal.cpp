//
// Created by BrandonZu on 10/30/21.
//

#include "common.h"
#include "TreeNode.h"

// Runtime 4ms(>60%) | Memory Usage 12MB(>77%)
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(!root) return result;
        bool left = false;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            left = !left;
            int size = q.size();
            vector<int> level(size);
            for(int i = 0; i < size; i++) {
                auto p = q.front();
                q.pop();
                if(left)
                    level[i] = p->val;
                else
                    level[size - 1 - i] = p->val;
                if(p->left) q.push(p->left);
                if(p->right) q.push(p->right);
            }
            result.push_back(level);
        }
        return result;
    }
};
