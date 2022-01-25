//
// Created by BrandonZu on 10/1/21.
//

#include "common.h"
#include "TreeNode.h"

// Runtime 12ms(>97%) | Memory Usage 16MB(>36%)
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        return dfs(1, n);
    }

    vector<TreeNode*> dfs(int l, int r) {
        if(l > r) return {nullptr};
        vector<TreeNode*> res;

        for(int root = l; root <= r; root++) {
            auto leftSubTree = dfs(l, root - 1), rightSubTree = dfs(root + 1, r);
            for(auto& leftRoot: leftSubTree) {
                for(auto& rightRoot: rightSubTree) {
                    TreeNode* head = new TreeNode(root);
                    head->left = leftRoot, head->right = rightRoot;
                    res.push_back(head);
                }
            }
        }

        return res;
    }
};

// 1st Review
// Runtime 26ms(>30%) | Memory Usage 15.5MB(>83%)
class Solution_R1 {
public:
    vector<TreeNode*> recur(int l, int r) {
        if(l > r) {
            return {nullptr};
        }
        if(l == r) {
            return {new TreeNode(l)};
        }
        vector<TreeNode*> ret;
        for(int i = l; i <= r; i++) {
            auto left = recur(l, i - 1), right = recur(i + 1, r);
            for(auto p: left) {
                for(auto q: right) {
                    TreeNode* root = new TreeNode(i, p, q);
                    ret.push_back(root);
                }
            }
        }
        return ret;
    }

    vector<TreeNode*> generateTrees(int n) {
        return recur(1, n);
    }
};
