//
// Created by BrandonZu on 2021/7/6.
//

#include "iostream"
#include "vector"
#include "queue"
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

class Solution {
    vector<vector<int>> result;
    vector<int> cur_path;
    int curValue = 0, target = 0;
public:
    vector<vector<int>> pathSum(TreeNode *root, int targetSum) {
        if (!root) return result;
        target = targetSum;
        dfs(root);
        return result;
    }

    void dfs(TreeNode *root) {
        if(!root)
            return;

        curValue += root->val;
        cur_path.push_back(root->val);
        if(!root->left && !root->right && curValue == target) {
            result.push_back(cur_path);
        }
        dfs(root->left);
        dfs(root->right);
        cur_path.pop_back();
        curValue -= root->val;
    }
};