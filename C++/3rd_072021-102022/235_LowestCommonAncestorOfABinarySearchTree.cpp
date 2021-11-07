//
// Created by BrandonZu on 2021/7/13.
//

#include "common.h"
#include "TreeNode.h"
using namespace std;

// Runtime 28ms(>80%) | Memory Cost 23.3MB(>55%)
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return nullptr;
        if((root->val <= p->val && root->val >= q->val) || (root->val <= q->val && root->val >= p->val))
            return root;
        TreeNode* l = nullptr, * r = nullptr;
        if(root->left)
            l = lowestCommonAncestor(root->left, p, q);
        if(root->right)
            r = lowestCommonAncestor(root->right, p, q);
        if(l)
            return l;
        else
            return r;
    }
};

// 1st Reiew 09/24/21
// Runtime 28ms(>82%) | Memory Cost 23MB(65%)
class Solution_R1 {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if((root->val >= p->val && root->val <= q->val) || (root->val >= q->val && root->val <= p->val))
            return root;

        if(p->val > root->val && q->val > root->val) {
            return lowestCommonAncestor(root->right, p, q);
        }
        else {
            return lowestCommonAncestor(root->left, p, q);
        }
    }
};