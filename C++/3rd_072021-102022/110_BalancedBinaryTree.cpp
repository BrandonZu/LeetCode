//
// Created by BrandonZu on 9/19/21.
//

#include "common.h"
#include "TreeNode.h"

// Runtime 32ms(>6%) | Memory Usage 20.7MB(>100%)
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return judge(root) != -1;
    }

    int judge(TreeNode* root) {
        if(!root) return 0;
        int l = judge(root->left);
        int r = judge(root->right);

        if(l == -1 || r == -1)
            return -1;

        if(abs(l - r) > 1)
            return -1;
        else
            return max(l, r) + 1;
    }
};

// R .94 | M .26
class Solution2 {
public:
    bool flag = true;
    bool isBalanced(TreeNode* root) {
        getHeight(root);
        return flag;
    }

    int getHeight(TreeNode* root) {
        if(!root) return 0;
        if(!flag) return -1;
        int l = getHeight(root->left), r = getHeight(root->right);
        if(abs(l - r) > 1) {
            flag = false;
            return -1;
        }
        return max(l, r) + 1;
    }
};
