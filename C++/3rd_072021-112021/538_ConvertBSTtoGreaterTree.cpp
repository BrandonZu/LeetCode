//
// Created by BrandonZu on 2021/7/14.
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

// Runtime 36ms(>70%) | Memory Cost 33MB(>90%)
class Solution {
public:
    TreeNode* convertBST(TreeNode* root) {
        int curSum = 0;
        postorder(root, curSum);
        return root;
    }

    void postorder(TreeNode* root, int& curSum) {
        if(!root) return;
        if(root->right)
            postorder(root->right, curSum);

        curSum += root->val;
        root->val = curSum;

        if(root->left)
            postorder(root->left, curSum);
    }
};
