//
// Created by BrandonZu on 11/16/21.
//

#include "common.h"
#include "TreeNode.h"

// Runtime 0ms(>100%) | Memory Usage 7.7MB(>76%)
class Solution {
    TreeNode* pre;
    TreeNode* head;
public:
    void inorder(TreeNode* root) {
        if(!root) return;
        inorder(root->left);
        pre->right = root;
        pre = root;
        root->left = nullptr;
        inorder(root->right);
    }

    TreeNode* increasingBST(TreeNode* root) {
        head = new TreeNode(-1);
        pre = head;
        inorder(root);
        return head->right;
    }
};
