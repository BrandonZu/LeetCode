//
// Created by BrandonZu on 2021/7/11.
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

// Runtime 20ms(>66%) | Memory Storage 26MB(>85%)
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.empty() || postorder.empty())
            return nullptr;
        return recurBuild(postorder, inorder, 0, postorder.size() - 1, 0, inorder.size() - 1);
    }

    TreeNode* recurBuild(vector<int>& postorder, vector<int>& inorder, int post_l, int post_r, int in_l, int in_r) {
        if(post_l > post_r)
            return nullptr;
        else if(post_l == post_r)
            return new TreeNode(postorder[post_l]);
        int pos = find(inorder.begin() + in_l, inorder.begin() + in_r, postorder[post_r]) - inorder.begin();
        TreeNode* root = new TreeNode(postorder[post_r]);
        root->right = recurBuild(postorder, inorder, post_r - (in_r - pos), post_r - 1, pos + 1, in_r);
        root->left = recurBuild(postorder, inorder, post_l, post_r - (in_r - pos) - 1, in_l, pos - 1);
        return root;
    }
};