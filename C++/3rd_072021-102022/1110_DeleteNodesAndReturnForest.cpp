//
// Created by BrandonZu on 12/8/21.
//

#include "common.h"
#include "TreeNode.h"

// Runtime 22ms(>62%) | Memory Usage 25.3MB(>62%)
class Solution {
    vector<TreeNode*> res;
    unordered_set<int> del;
public:
    void dfs(TreeNode* root, bool r_exist) {
        if(!root) return;
        if(del.find(root->val) == del.end() && !r_exist) {
            res.push_back(root);
        }
        bool root_exist = del.find(root->val) == del.end();
        if(root->left) {
            dfs(root->left, root_exist);
            if(del.find(root->left->val) != del.end()) {
                root->left = nullptr;
            }
        }
        if(root->right) {
            dfs(root->right, root_exist);
            if(del.find(root->right->val) != del.end()) {
                root->right = nullptr;
            }
        }
    }

    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        for(int i: to_delete) del.insert(i);
        dfs(root, false);
        return res;
    }
};

