//
// Created by BrandonZu on 2021/7/5.
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
    int minDepth(TreeNode* root) {
        if(!root)
            return 0;
        int l = minDepth(root->left), r = minDepth(root->right);
        // Pay Attention to l == 0 or r == 0
        if(l != 0 && r != 0)
            return min(l, r) + 1;
        else
            return l == 0 ? r + 1 : l + 1;
    }
};