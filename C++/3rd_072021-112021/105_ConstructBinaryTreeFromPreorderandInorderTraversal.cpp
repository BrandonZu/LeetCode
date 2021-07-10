//
// Created by BrandonZu on 2021/7/6.
//

#include "vector"
#include "queue"
#include "stack"
#include "algorithm"
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(): val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Runtime 28ms(>56%) | Memory Usage 25.7MB(>96%)
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.empty() || inorder.empty())
            return nullptr;
        return recurBuild(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }

    TreeNode* recurBuild(vector<int>& preorder, vector<int>& inorder, int pre_l, int pre_r, int in_l, int in_r) {
        if(pre_l > pre_r)
            return nullptr;
        else if(pre_l == pre_r)
            return new TreeNode(preorder[pre_l]);
        TreeNode* root = new TreeNode(preorder[pre_l]);
        int pos = find(inorder.begin() + in_l, inorder.end(), preorder[pre_l]) - inorder.begin();
        root->left = recurBuild(preorder, inorder, pre_l + 1, pre_l + pos - in_l, in_l, pos - 1);
        root->right = recurBuild(preorder, inorder, pre_l + pos - in_l + 1, pre_r, pos + 1, in_r);
        return root;
    }
};