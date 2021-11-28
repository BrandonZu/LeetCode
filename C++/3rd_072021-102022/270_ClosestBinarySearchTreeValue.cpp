//
// Created by BrandonZu on 11/27/21.
//

#include "common.h"
#include "TreeNode.h"

// Runtime 12ms(>63%) | Memory Usage 21MB(>33%)
class Solution {
public:
    int closestValue(TreeNode* root, double target) {
        double dist = 1e8;
        int res;
        while(root) {
            if(abs(root->val - target) < dist) {
                res = root->val;
                dist = abs(root->val - target);
            }
            if(root->val > target) {
                root = root->left;
            }
            else {
                root = root->right;
            }
        }
        return res;
    }
};
