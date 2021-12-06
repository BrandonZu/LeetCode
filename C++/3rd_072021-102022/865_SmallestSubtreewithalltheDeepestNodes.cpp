//
// Created by BrandonZu on 12/6/21.
//

#include "common.h"
#include "TreeNode.h"

// Runtime 0ms(>100%) | Memory Usage 14.4MB(>76%)
class Solution {
public:
    pair<int, TreeNode*> helper(TreeNode* root, int depth) {
        if(!root) return {depth, root};
        if(!root->left && !root->right) return {depth, root};
        pair<int, TreeNode*> l, r;
        if(root->left)
            l = helper(root->left, depth + 1);
        if(root->right)
            r = helper(root->right, depth + 1);
        if(root->left && root->right) {
            if(l.first == r.first) {
                return {l.first, root};
            }
            else {
                return l.first > r.first ? l : r;
            }
        }
        else {
            return root->left ? l : r;
        }
    }

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        auto p = helper(root, 0);
        return p.second;
    }
};

