//
// Created by BrandonZu on 2021/7/13.
//

#include "common.h"
#include "TreeNode.h"

// Runtime 12ms(>94.2%) | Memory Cost 14.4MB(>29%)
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* l = nullptr, * r = nullptr;
        if(root->left) l = lowestCommonAncestor(root->left, p, q);
        if(root->right) r = lowestCommonAncestor(root->right, p, q);

        if(l && r)
            return root;

        if(root == p || root == q)
            return root;

        if(l) return l;
        if(r) return r;

        return nullptr;
    }
};

// 1st Review 09/24/21
// Runtime 16ms(>73%) | Memory Cost 14MB(28%)
class Solution_R1 {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* l = nullptr, * r = nullptr;
        if(root->left)
            l = lowestCommonAncestor(root->left, p, q);
        if(root->right)
            r = lowestCommonAncestor(root->right, p, q);

        if(root == p || root == q)
            return root;

        if(l && r)
            return root;
        else if(l)
            return l;
        else if(r)
            return r;
        return nullptr;
    }
};

// 2nd Review 12/12/21
// Runtime 16ms(>73%) | Memory Cost 14MB(28%)
class Solution_R2 {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return nullptr;
        TreeNode* l = lowestCommonAncestor(root->left, p, q);
        TreeNode* r = lowestCommonAncestor(root->right, p, q);
        if(root->val == p->val || root->val == q->val) {
            return root;
        }
        if(l && r)
            return root;
        else if(l)
            return l;
        else if(r)
            return r;
        else
            return nullptr;
    }
};

// R .74 | M .57
class Solution3 {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return nullptr;
        TreeNode* l = lowestCommonAncestor(root->left, p, q);
        TreeNode* r = lowestCommonAncestor(root->right, p, q);
        if(root == p || root == q) {
            return root;
        }
        else if(l && r) {
            return root;
        }
        else if(l) {
            return l;
        }
        else if(r) {
            return r;
        }
        else {
            return nullptr;
        }
    }
};
