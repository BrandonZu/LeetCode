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