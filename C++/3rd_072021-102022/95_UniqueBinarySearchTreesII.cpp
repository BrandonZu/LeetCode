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
