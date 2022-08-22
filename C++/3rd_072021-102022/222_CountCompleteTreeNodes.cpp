//
// Created by BrandonZu on 2021/7/5.
//

#include "common.h"
#include "TreeNode.h"

class Solution {
public:
    int getDepth(TreeNode* root) {
        int dep = 0;
        TreeNode* cur = root;
        while(cur) {
            dep++;
            cur = cur->left;
        }
        return dep;
    }

    int countNodes(TreeNode* root) {
        int node_num = 0;
        if(!root) return node_num;
        queue<TreeNode*> myQ;
        myQ.push(root);

        int depth = getDepth(root);

        for(int i = 0; i < depth - 1; i++) {
            int size = myQ.size();
            node_num += size;
            for(int j = 0; j < size; j++) {
                TreeNode* cur = myQ.front();
                myQ.pop();
                if(cur->left) myQ.push(cur->left);
                if(cur->right) myQ.push(cur->right);
            }
        }
        // 最深一层
        node_num += myQ.size();
        int size = myQ.size();
        for(int i = 0; i < size; i++) {
            if(myQ.front()->left) node_num++;
            if(myQ.front()->right) node_num++;
            myQ.pop();
        }
        return node_num;
    }
};

// R .76 | M .64
class Solution2 {
public:
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        int l = 1, r = 1;
        TreeNode* lNode = root->left, * rNode = root->right;
        while(lNode) {
            lNode = lNode->left;
            ++l;
        }
        while(rNode) {
            rNode = rNode->right;
            ++r;
        }
        if(l == r) {
            return (1 << l) - 1;
        }
        else {
            return countNodes(root->left) + countNodes(root->right) + 1;
        }
    }
};