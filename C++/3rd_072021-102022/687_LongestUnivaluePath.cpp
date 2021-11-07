//
// Created by BrandonZu on 10/30/21.
//

#include "common.h"
#include "TreeNode.h"

// Runtime 120ms(>81%) | Memory Usage 72MB(>45%)
class Solution {
    int maxLen = 1;
public:
    int postOrder(TreeNode* root) {
        int l = 0, r = 0;
        if(root->left)
            l = postOrder(root->left);
        if(root->right)
            r = postOrder(root->right);
        if(root->left && root->left->val == root->val && root->right && root->right->val == root->val) {
            maxLen = max(maxLen, l + r + 1);
            return max(l, r) + 1;
        }
        else if(root->left && root->left->val == root->val) {
            maxLen = max(maxLen, l + 1);
            return l + 1;
        }
        else if(root->right && root->right->val == root->val) {
            maxLen = max(maxLen, r + 1);
            return r + 1;
        }
        else {
            return 1;
        }
    }

    int longestUnivaluePath(TreeNode* root) {
        if(!root) return 0;
        postOrder(root);
        return maxLen - 1;
    }
};
