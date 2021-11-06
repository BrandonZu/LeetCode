//
// Created by BrandonZu on 11/6/21.
//

#include "common.h"
#include "TreeNode.h"

// Runtime 104ms(86%) | Memory Usage 47MB(>71%)
class Solution {
    vector<TreeNode*> node_list;
public:
    void inorder(TreeNode* root) {
        if(!root) return;
        inorder(root->left);
        node_list.push_back(root);
        inorder(root->right);
    }

    TreeNode* buildBST(int l, int r) {
        if(l > r) return nullptr;
        if(l == r) {
            // Need to set the left and right pointers of leaves to null
            node_list[l]->left = node_list[r]->right = nullptr;
            return node_list[l];
        }
        int mid = (l + r) / 2;
        node_list[mid]->left = buildBST(l, mid - 1);
        node_list[mid]->right = buildBST(mid + 1, r);
        return node_list[mid];
    }

    TreeNode* balanceBST(TreeNode* root) {
        inorder(root);
        return buildBST(0, node_list.size() - 1);
    }
};

