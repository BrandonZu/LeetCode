//
// Created by BrandonZu on 2021/7/11.
//

#include "vector"
#include "stack"
#include "unordered_map"
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

// Runtime 28ms(>66%) | Memory Usage 24MB(>53%)
class BSTIterator {
    stack<TreeNode*> myStack;
public:
    BSTIterator(TreeNode* root) {
        TreeNode* cur = root;
        while(cur) {
            myStack.push(cur);
            cur = cur->left;
        }
    }

    int next() {
        TreeNode* root = myStack.top();
        myStack.pop();
        TreeNode* cur = root->right;
        while(cur) {
            myStack.push(cur);
            cur = cur->left;
        }
        return root->val;
    }

    bool hasNext() {
        return !myStack.empty();
    }
};