//
// Created by BrandonZu on 12/11/21.
//

#include "common.h"
#include "TreeNode.h"

// Runtime 32ms(>81%) | Memory Usage 32.6MB(>63%)
class Solution {
    int max_len;
public:
    int postorder(TreeNode* root) {
        int l = 0, r = 0;
        if(root->left) {
            int tmp = postorder(root->left);
            if(root->left->val == root->val + 1) {
                l = tmp;
                max_len = max(max_len, l + 1);
            }
        }
        if(root->right) {
            int tmp = postorder(root->right);
            if(root->right->val == root->val + 1) {
                r = tmp;
                max_len = max(max_len, r + 1);
            }
        }

        return max(l + 1, r + 1);
    }

    int longestConsecutive(TreeNode* root) {
        if(!root) return 0;
        max_len = 1;
        postorder(root);
        return max_len;
    }
};
