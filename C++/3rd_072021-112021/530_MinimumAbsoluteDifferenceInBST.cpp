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

// Runtime 12ms(>94%) | Memory Usage 25.1MB(>77%)
class Solution {
    TreeNode* preNode = nullptr;
    int minDiff = INT_MAX;
public:
    int getMinimumDifference(TreeNode* root) {
        if(!root)
            return 0;
        inorder(root);
        return minDiff;
    }

    void inorder(TreeNode* root) {
        if(root->left)
            inorder(root->left);
        if(preNode)
            minDiff = min(minDiff, root->val - preNode->val);
        preNode = root;
        if(root->right)
            inorder(root->right);
    }
};
