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