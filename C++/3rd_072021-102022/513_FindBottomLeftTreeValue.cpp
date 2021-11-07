//
// Created by BrandonZu on 2021/7/6.
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

// Runtime 8ms(>88%) | Memory Usage 21.9MB(>33%)
class Solution_BFS {
public:
    int findBottomLeftValue(TreeNode* root) {
        int result = 0;
        if(!root) return result;
        queue<TreeNode*> myQ;
        myQ.push(root);
        while(!myQ.empty()) {
            result = myQ.front()->val;
            int size = myQ.size();
            for(int i = 0; i < size; i++) {
                TreeNode* cur = myQ.front();
                myQ.pop();
                if(cur->left) myQ.push(cur->left);
                if(cur->right) myQ.push(cur->right);
            }
        }

        return result;
    }
};

// Runtime 8ms(>88%) | Memory Usage 21.7MB(>80%)
class Solution_DFS {
    int max_depth = 0;
    int result = 0;
public:
    int findBottomLeftValue(TreeNode* root) {
        if(!root)
            return result;
        dfs(root, 1);
        return result;
    }

    void dfs(TreeNode* root, int cur_depth) {
        if(!root)
            return;

        dfs(root->left, cur_depth + 1);
        dfs(root->right, cur_depth + 1);

        if(cur_depth > max_depth) {
            max_depth = cur_depth;
            result = root->val;
        }
    }
};