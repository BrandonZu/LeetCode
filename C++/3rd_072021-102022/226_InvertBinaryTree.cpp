//
// Created by BrandonZu on 2021/7/1.
//

#include "common.h"
#include "TreeNode.h"

class Solution {
public:
    TreeNode* traversal(TreeNode* root) {
        if(!root) return nullptr;
        TreeNode* l = traversal(root->left);
        TreeNode* r = traversal(root->right);
        root->left = r;
        root->right = l;
        return root;
    }

    TreeNode* invertTree(TreeNode* root) {
        return traversal(root);
    }
};

// R .50 | M .80
class Solution2 {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return root;
        swap(root->left, root->right);
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};