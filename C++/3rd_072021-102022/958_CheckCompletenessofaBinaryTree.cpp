//
// Created by BrandonZu on 11/28/21.
//

#include "common.h"
#include "TreeNode.h"

// Runtims 4ms(>79%) | Memory Usage 11MB(>22%)
class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        bool isLast = false;
        while(!q.empty() && !isLast) {
            int sz = q.size();
            bool is = false;
            for(int i = 0; i < sz; i++) {
                auto p = q.front();
                q.pop();
                if(isLast) {
                    if(p)
                        return false;
                    else
                        continue;
                }
                if(!p)
                    isLast = true;
                else
                    q.push(p->left), q.push(p->right);
            }
        }
        while(!q.empty()) {
            if(q.front()) return false;
            q.pop();
        }
        return true;
    }
};
