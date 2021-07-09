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
    vector<int> result;
public:
    void traversal(TreeNode* root) {
        if(!root) return;
        traversal(root->left);
        traversal(root->right);
        result.push_back(root->val);
    }

    vector<int> postorderTraversal(TreeNode* root) {
        result.clear();
        traversal(root);
        return result;
    }
};