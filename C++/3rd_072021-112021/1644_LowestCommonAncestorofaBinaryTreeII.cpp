//
// Created by BrandonZu on 9/24/21.
//

#include "common.h"
#include "TreeNode.h"

// Runtime 124ms(>78%) | Memory Usage 61.6MB(>88%)
class Solution {
    TreeNode* ans = nullptr;
public:
    int postorder(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(ans) return 0;
        int cnt = 0;
        if(root->left)
            cnt += postorder(root->left, p, q);
        if(root->right)
            cnt += postorder(root->right, p, q);

        cnt += root == p || root == q;
        if(cnt == 2 && !ans) {
            ans = root;
        }
        return cnt;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        postorder(root, p, q);
        return ans;
    }
};

// Runtime 120ms(>88%) | Memory Usage 61.8MB(>38%)
class Solution_1 {
    TreeNode* ans = nullptr;
public:
    TreeNode* postorder(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(ans) return nullptr;

        TreeNode* l = nullptr, * r = nullptr;
        if(root->left)
            l = postorder(root->left, p, q);
        if(root->right)
            r = postorder(root->right, p, q);

        if(root == p || root == q) {
            if(l || r)
                ans = root;
            return root;
        }
        if(l && r) {
            ans = root;
            return root;
        }
        if(l) return l;
        if(r) return r;
        return nullptr;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        postorder(root, p, q);
        return ans;
    }
};

