//
// Created by BrandonZu on 2021/7/1.
//

#include "iostream"
#include "vector"
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(): val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* traversal(TreeNode* root) {
        if(!root) return nullptr;
        TreeNode* l = traversal(root->left);
        TreeNode* r = traversal(root->right);
        root->left = r;
        root->right = l;
        return root;
    }

    TreeNode* invertTree(TreeNode* root) {
        return traversal(root);
    }
};