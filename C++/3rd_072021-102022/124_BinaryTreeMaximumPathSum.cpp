//
// Created by BrandonZu on 2021/8/11.
//

#include "common.h"
#include "TreeNode.h"

// Runtime 24ms(>66%) | Memory Usage 27.6MB(>95%)
class Solution {
    int res = INT_MIN;
public:
    int postOrder(TreeNode* root) {
        if(!root->left && !root->right) {
            res = max(res, root->val);
            return root->val;
        }

        int l = 0, r = 0;
        if(root->left)
            l = postOrder(root->left);
        if(root->right)
            r = postOrder(root->right);

        res = max(res, root->val + max(0, l) + max(0, r));
        return root->val + max(max(0, l), max(0, r));
    }

    int maxPathSum(TreeNode* root) {
        postOrder(root);
        return res;
    }
};
