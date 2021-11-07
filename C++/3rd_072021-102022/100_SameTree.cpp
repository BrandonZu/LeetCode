//
// Created by BrandonZu on 9/30/21.
//

#include "common.h"
#include "TreeNode.h"

// Runtime 0ms(>100%) | Memory Usage 10MB(>8%)
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q) return true;
        if(!p || !q) return false;
        if(p->val != q->val)
            return false;
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};
