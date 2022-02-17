//
// Created by BrandonZu on 2/17/22.
//

#include "common.h"
#include "TreeNode.h"

// Runtime 26ms(>47%) | Memory Usage 24.2MB(>61%)
class Solution {
public:
    int value = -1;
    void inorder(TreeNode* root, int& k) {
        if(!k) return;
        if(!root) return;
        if(root->left) {
            inorder(root->left, k);
        }
        k--;
        if(k == 0) {
            value = root->val;
            return;
        }
        if(root->right) {
            inorder(root->right, k);
        }
    }

    int kthSmallest(TreeNode* root, int k) {
        inorder(root, k);
        return value;
    }
};
