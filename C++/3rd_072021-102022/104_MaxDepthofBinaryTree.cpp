//
// Created by BrandonZu on 2021/7/5.
//

#include "common.h"
#include "TreeNode.h"

class Solution_DFS {
    int result = 0;
public:
    int maxDepth(TreeNode* root) {
        if (!root)
            return 0;
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};

class Solution_BFS {
public:
    int maxDepth(TreeNode* root) {
        int result = 0;
        if(!root) return result;
        queue<TreeNode*> myQ;
        myQ.push(root);
        while(!myQ.empty()) {
            int size = myQ.size();
            for(int i = 0; i < size; i++) {
                TreeNode* cur = myQ.front();
                myQ.pop();
                if(cur->left) myQ.push(cur->left);
                if(cur->right) myQ.push(cur->right);
            }
            result ++;
        }
        return result;
    }
};

// R .31 | M .14
class Solution {
    queue<TreeNode*> q;
public:
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        int cnt = 0;
        q.push(root);
        while(!q.empty()) {
            int sz = q.size();
            for(int i = 0; i < sz; i++) {
                if(q.front()->left) q.push(q.front()->left);
                if(q.front()->right) q.push(q.front()->right);
                q.pop();
            }
            cnt++;
        }
        return cnt;
    }
};