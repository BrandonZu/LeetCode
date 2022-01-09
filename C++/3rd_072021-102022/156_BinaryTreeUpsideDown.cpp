//
// Created by BrandonZu on 1/9/22.
//

#include "common.h"
#include "TreeNode.h"

// Runtime 0ms(>100%) | Memory Usage 9.7MB(>15%)
class Solution_Recur {
public:
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        TreeNode* res = root;
        while(res && res->left) {
            res = res->left;
        }
        postOrder(root);
        return res;
    }

    void postOrder(TreeNode* root) {
        if(!root || !root->left)
            return;
        postOrder(root->left);
        root->left->left = root->right;
        root->left->right = root;
        root->left = root->right = nullptr;
    }
};

// Runtime 10ms(>6%) | Memory Usage 9.7MB(>15%)
class Solution_Iter {
public:
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        if(!root) return root;
        TreeNode* cur = root, * prev = nullptr;
        TreeNode* prev_right = nullptr;
        while(cur) {
            TreeNode* next = cur->left;
            cur->left = prev_right;
            prev_right = cur->right;
            cur->right = prev;

            prev = cur;
            cur = next;
        }
        root->left = root->right = nullptr;
        return prev;
    }
};

