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

// Runtime 0ms(>100%) | Memory Cost 13.3MB(>78%)
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* node) {
        if(!node) return 0;
        if(node->left && !node->left->left && !node->left->right)
            return node->left->val + sumOfLeftLeaves(node->left) + sumOfLeftLeaves(node->right);
        else
            return sumOfLeftLeaves(node->left) + sumOfLeftLeaves(node->right);
    }
};

// Runtime 0ms(>100%) | Memory Cost 13.5MB(>40%)
class Solution_1 {
public:
    int sumOfLeftLeaves(TreeNode* node) {
        if(!node || (!node->left && !node->right))
            return 0;
        else
            return recur(node);
    }

    int recur(TreeNode* node) {
        if(!node)
            return 0;
        else if(!node->left && !node->right)
            return node->val;

        if(node->right && !node->right->left && !node->right->right)
            return recur(node->left);
        else
            return recur(node->left) + recur(node->right);
    }
};