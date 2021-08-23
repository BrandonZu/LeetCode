//
// Created by BrandonZu on 2021/7/12.
//

#include "common.h"
#include "TreeNode.h"
using namespace std;

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

// 1st Review 08/23/2021
// Runtime 4ms(>99%) | Memory Cost 21.8MB(>32%)
class Solution_R1 {
    TreeNode* pre;
public:
    bool isValidBST(TreeNode* root) {
        if(!root) return true;

        if(!isValidBST(root->left))
            return false;

        if(pre && pre->val >= root->val)
            return false;
        pre = root;

        if(!isValidBST(root->right))
            return false;
        return true;
    }
};