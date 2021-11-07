//
// Created by BrandonZu on 11/4/21.
//

#include "common.h"
#include "TreeNode.h"

// Runtime 8ms(>84%) | Memory Usage 20MB(>92%)
class Solution {
    int ans = 0;
public:
    int helper(TreeNode* root) {
        if(!root)
            return 0;
        int l = helper(root->left);
        int r = helper(root->right);
        ans = max(ans, l + r);
        return max(l, r) + 1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        helper(root);
        return ans;
    }
};
