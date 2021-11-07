//
// Created by BrandonZu on 2021/7/13.
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

// Recursion
// Runtime 88ms(>60%) | Memory Cost 57MB(>44%)
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root) return new TreeNode(val);
        if(root->val < val)
            root->right = insertIntoBST(root->right, val);
        else
            root->left = insertIntoBST(root->left, val);
        return root;
    }
};

// Iteration
// Runtime 140ms(>10%) | Memory Cost 57MB(>44%)
class SolutionII {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root) return new TreeNode(val);
        auto* cur = root;
        auto* pre = root;
        while(cur) {
            if(val > cur->val) {
                pre = cur;
                cur = cur->right;
            }
            else {
                pre = cur;
                cur = cur->left;
            }
        }
        if(val > pre->val)
            pre->right = new TreeNode(val);
        else
            pre->left = new TreeNode(val);
        return root;
    }
};