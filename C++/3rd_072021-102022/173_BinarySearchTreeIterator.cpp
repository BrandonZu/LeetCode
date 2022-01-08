//
// Created by BrandonZu on 2021/7/11.
//

#include "common.h"
#include "TreeNode.h"

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

// 1st Review 12/12/21
// Runtime 24ms(>87%) | Memory Usage 24MB(>86%)
class BSTIterator_R1 {
    stack<TreeNode*> stk;
public:
    BSTIterator_R1(TreeNode* root) {
        while(root) {
            stk.push(root);
            root = root->left;
        }
    }

    int next() {
        auto p = stk.top();
        stk.pop();
        for(auto i = p->right; i; i = i->left) {
            stk.push(i);
        }
        return p->val;
    }

    bool hasNext() {
        return !stk.empty();
    }
};