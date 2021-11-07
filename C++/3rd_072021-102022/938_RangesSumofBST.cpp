//
// Created by BrandonZu on 11/3/21.
//

#include "common.h"
#include "TreeNode.h"

// Runtime 128ms(>55%) | Memory Usage 65MB(>60%)
class Solution {
    int l, h;
    int sum;
public:
    void inorder(TreeNode* root) {
        if(!root) return;
        if(root->val >= l)
            inorder(root->left);
        if(root->val >= l && root->val <= h)
            sum += root->val;
        if(root->val <= h)
            inorder(root->right);
    }

    int rangeSumBST(TreeNode* root, int low, int high) {
        sum = 0;
        l = low, h = high;
        inorder(root);
        return sum;
    }
};
