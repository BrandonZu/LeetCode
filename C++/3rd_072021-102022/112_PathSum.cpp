//
// Created by BrandonZu on 2021/7/6.
//

#include "iostream"
#include "vector"
#include "queue"
#include "stack"
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(): val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Runtime 16ms(>26%) | Memory Usage 21.1MB(>99%)
class Solution_Recursive {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) return false;

        targetSum -= root->val;
        if(!root->left && !root->right && targetSum == 0)
            return true;
        bool result = hasPathSum(root->left, targetSum) || hasPathSum(root->right, targetSum);

        return result;
    }
};


// Runtime 8ms(>88%) | Memory Usage 21.4MB(>22%)
class Solution_Iterative {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root)
            return false;
        stack<pair<TreeNode*, int>> stack;
        stack.push({root, root->val});
        while(!stack.empty()) {
            TreeNode* cur_node = stack.top().first;
            int cur_sum = stack.top().second;
            stack.pop();
            if(!cur_node->left && !cur_node->right && cur_sum == targetSum)
                return true;
            if(cur_node->right)
                stack.push({cur_node->right, cur_sum + cur_node->right->val});
            if(cur_node->left)
                stack.push({cur_node->left, cur_sum + cur_node->left->val});
        }
        return false;
    }
};
