//
// Created by BrandonZu on 2021/7/5.
//

#include "iostream"
#include "vector"
#include "queue"
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(): val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

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