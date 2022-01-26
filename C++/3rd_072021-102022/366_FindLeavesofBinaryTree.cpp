//
// Created by BrandonZu on 1/26/22.
//

#include "common.h"
#include "TreeNode.h"

// Runtime 0ms(>100%) | Memory Usage 9MB(>42%)
class Solution {
public:
    int maxDepth = 0;

    int dfs(vector<vector<int>>& nodeList, TreeNode* root) {
        if(!root) return -1;
        int l = dfs(nodeList, root->left);
        int r = dfs(nodeList, root->right);
        int cur = max(l, r) + 1;
        if(cur == nodeList.size()) {
            nodeList.emplace_back();
        }
        nodeList[cur].push_back(root->val);
        return cur;
    }

    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> nodeList;
        dfs(nodeList, root);
        return nodeList;
    }
};
