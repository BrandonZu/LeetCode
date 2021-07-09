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
    void traversal(TreeNode* root, vector<int>& result) {
        if(!root)
            return;
        result.push_back(root->val);
        traversal(root->left, result);
        traversal(root->right, result);
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        traversal(root, result);
        return result;
    }
};

