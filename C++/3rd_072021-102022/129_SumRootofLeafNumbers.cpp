//
// Created by BrandonZu on 12/5/21.
//

#include "common.h"
#include "TreeNode.h"

// Runtime 0ms(>100%) | Memory Usage 9MB(>75%)
class Solution {
    int cur = 0;
    int total = 0;
public:
    void recur(TreeNode* root) {
        if(!root)
            return;
        if(!root->left && !root->right) {
            total += cur + root->val;
            return;
        }
        cur += root->val;
        cur *= 10;
        if(root->left)
            recur(root->left);
        if(root->right)
            recur(root->right);
        cur /= 10;
        cur -= root->val;
    }

    int sumNumbers(TreeNode* root) {
        recur(root);
        return total;
    }
};
