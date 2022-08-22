//
// Created by BrandonZu on 2021/7/11.
//

#include "common.h"
#include "TreeNode.h"

// Runtime 0ms(>100%) | Memory Cost 13.3MB(>78%)
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* node) {
        if(!node) return 0;
        if(node->left && !node->left->left && !node->left->right)
            return node->left->val + sumOfLeftLeaves(node->left) + sumOfLeftLeaves(node->right);
        else
            return sumOfLeftLeaves(node->left) + sumOfLeftLeaves(node->right);
    }
};

// Runtime 0ms(>100%) | Memory Cost 13.5MB(>40%)
class Solution_1 {
public:
    int sumOfLeftLeaves(TreeNode* node) {
        if(!node || (!node->left && !node->right))
            return 0;
        else
            return recur(node);
    }

    int recur(TreeNode* node) {
        if(!node)
            return 0;
        else if(!node->left && !node->right)
            return node->val;

        if(node->right && !node->right->left && !node->right->right)
            return recur(node->left);
        else
            return recur(node->left) + recur(node->right);
    }
};

// R .75 | M .81
class Solution2 {
public:
    int cnt = 0;
    int sumOfLeftLeaves(TreeNode* root) {
        helper(root, nullptr);
        return cnt;
    }

    void helper(TreeNode* root, TreeNode* parent) {
        if(!root) return;
        if(!root->left && !root->right && parent && root == parent->left) {
            cnt += root->val;
            return;
        }
        helper(root->left, root);
        helper(root->right, root);
    }
};