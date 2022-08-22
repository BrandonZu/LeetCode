//
// Created by BrandonZu on 2021/7/2.
//

#include "common.h"
#include "TreeNode.h"

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(!root) return result;
        queue<TreeNode*> myQueue;
        myQueue.push(root);

        vector<int> curLevel;
        while(!myQueue.empty()) {
            curLevel.clear();
            int size = myQueue.size();
            for(int i = 0; i < size; i++) {
                TreeNode* cur = myQueue.front();
                curLevel.push_back(cur->val);
                myQueue.pop();
                if(cur->left)
                    myQueue.push(cur->left);
                if(cur->right)
                    myQueue.push(cur->right);
            }
            result.push_back(curLevel);
        }

        return result;
    }
};

// R .100 | M .63
class Solution2 {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) {
            return {};
        }
        vector<vector<int>> res;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            vector<int> level;
            int sz = q.size();
            for(int i = 0; i < sz; i++) {
                level.push_back(q.front()->val);
                if(q.front()->left) {
                    q.push(q.front()->left);
                }
                if(q.front()->right) {
                    q.push(q.front()->right);
                }
                q.pop();
            }
            res.push_back(level);
        }
        return res;
    }
};