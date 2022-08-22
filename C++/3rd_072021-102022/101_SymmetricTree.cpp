//
// Created by BrandonZu on 2021/7/5.
//

#include "common.h"
#include "TreeNode.h"

class Solution {
public:
    bool dfs(TreeNode* left, TreeNode* right) {
        if(!left && !right)
            return true;
        else if(!left || !right)
            return false;
        else if(left->val != right->val)
            return false;
        return dfs(left->left, right->right) && dfs(left->right, right->left);
    }
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        return dfs(root->left, root->right);
    }
};

// R .60 | M .9
class Solution2 {
public:
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        return helper(root->left, root->right);
    }

    bool helper(TreeNode* l, TreeNode* r) {
        if(!l && !r) return true;
        if(!l || !r) return false;
        if(l->val != r->val) return false;
        return helper(l->left, r->right) && helper(l->right, r->left);
    }
};