//
// Created by BrandonZu on 2021/7/13.
//

#include "iostream"
#include "vector"
#include "queue"
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(): val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

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
