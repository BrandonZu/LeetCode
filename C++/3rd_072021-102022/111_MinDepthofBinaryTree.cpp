//
// Created by BrandonZu on 2021/7/5.
//

#include "common.h"
#include "TreeNode.h"

// Runtime 216ms(>89%) | Memoru Usage 144MB(>67%)
class Solution_BFS {
public:
    int minDepth(TreeNode* root) {
        if(!root)
            return 0;
        int depth = 0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            depth++;
            int sz = q.size();
            for(int i = 0; i < sz; i++) {
                TreeNode* cur = q.front();
                if(!cur->left && !cur->right)
                    return depth;
                q.pop();
                if(cur->left) q.push(cur->left);
                if(cur->right) q.push(cur->right);
            }
        }
        return 0;
    }
};

// Runtime 228ms(>65%) | Memory Usage 145MB(>41%)
class Solution_DFS {
public:
    int minDepth(TreeNode* root) {
        if(!root)
            return 0;
        int l = minDepth(root->left), r = minDepth(root->right);
        // Pay Attention to l == 0 or r == 0
        if(l != 0 && r != 0)
            return min(l, r) + 1;
        else
            return l == 0 ? r + 1 : l + 1;
    }
};