//
// Created by BrandonZu on 2/19/22.
//

#include "common.h"
#include "TreeNode.h"

// Runtime 35ms(>58%) | Memory Usage 23MB(》48%)
class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if(p == root) {
            return p->right;
        }
        if(p->right) {
            p = p->right;
            while(p->left) {
                p = p->left;
            }
            return p;
        }
        TreeNode* cur = root, *prev = nullptr;
        while(cur) {
            if(cur->left && cur->left == p) {
                return cur;
            }
            if(cur->right && cur->right == p) {
                break;
            }
            if(cur->val < p->val) {
                cur = cur->right;
            }
            else {
                prev = cur;
                cur = cur->left;
            }
        }
        return prev;
    }
};
