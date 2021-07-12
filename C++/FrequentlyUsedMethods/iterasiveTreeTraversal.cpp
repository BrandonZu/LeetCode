//
// Created by BrandonZu on 2021/7/11.
//

// Iterative Tree Traversal
// Use stack to simulate the recursive call of functions in the Opreating System

#include "stack"
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(): val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class IterativeTreeTraversal {
public:
    void preorder(TreeNode* root) {
        stack<TreeNode*> trav;
        trav.push(root);
        while(!trav.empty()) {
            TreeNode* cur = trav.top();
            trav.pop();

            operation(cur);

            if(cur->right)
                trav.push(cur->right);
            if(cur->left)
                trav.push(cur->left);
        }
    }

    void inorder(TreeNode* root) {
        stack<pair<TreeNode*, bool>> trav;
        trav.push({root, false});
        while(!trav.empty()) {
            auto& cur = trav.top();
            if(!cur.second) {
                cur.second = true;
                if(cur.first->left)
                    trav.push({cur.first->left, false});
            }
            else {
                operation(cur.first);
                trav.pop();
                if(cur.first->right)
                    trav.push({cur.first->right, false});
            }
        }
    }

    void postorder(TreeNode* root) {
        stack<pair<TreeNode*, bool>> trav;
        trav.push({root, false});
        while(!trav.empty()) {
            auto& cur = trav.top();
            if(!cur.second) {
                cur.second = true;
                if(cur.first->right)
                    trav.push({cur.first->right, false});
                if(cur.first->left)
                    trav.push({cur.first->left, false});
            }
            else {
                operation(cur.first);
                trav.pop();
            }
        }
    }

    void operation(TreeNode* root) {
        // Custom Operation
    }
};