//
// Created by BrandonZu on 2021/7/12.
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

// Runtime 4ms(>99%) | Memory Cost 21.7MB(>65%)
class Solution {
    TreeNode* last_node = nullptr;
public:
    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        if(!isValidBST(root->left)) return false;

        if(!last_node || last_node->val < root->val)
            last_node = root;
        else
            return false;

        return isValidBST(root->right);
    }
};