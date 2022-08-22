//
// Created by BrandonZu on 2021/7/12.
//

#include "common.h"
#include "TreeNode.h"

// Runtime 36ms(>66%) | Memory Cost 32.3MB(>85%)
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(!root2)
            return root1;
        else if(!root1)
            return root2;
        else {
            root1->left = mergeTrees(root1->left, root2->left);
            root1->right = mergeTrees(root1->right, root2->right);
            root1->val += root2->val;
            return root1;
        }
    }
};

// R .71 | M .62
class Solution2 {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(!root1) {
            return root2;
        }
        else if(!root2) {
            return root1;
        }
        else {
            root1->val += root2->val;
            root1->left = mergeTrees(root1->left, root2->left);
            root1->right = mergeTrees(root1->right, root2->right);
            return root1;
        }
    }
};