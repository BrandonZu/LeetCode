//
// Created by BrandonZu on 2021/7/5.
//

#include "iostream"
#include "vector"
#include "string"
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(): val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Runtime 4ms(>75%) | Memory Usage 14.4MB(>5%)
class Solution_1 {
    vector<string> result;
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        dfs(root, "");
        return result;
    }

    void dfs(TreeNode* root, string cur_path) {
        if(!root) return;

        if(cur_path.empty())
            cur_path = to_string(root->val);
        else
            cur_path = cur_path + "->" + to_string(root->val);

        if(!root->left && !root->right)
            result.push_back(cur_path);

        dfs(root->left, cur_path);
        dfs(root->right, cur_path);
    }
};

// Runtime 4ms(>75%) | Memory Usage 12.7MB(>88%)
class Solution_2 {
    vector<string> result;
    vector<int> cur;
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        if(!root) return result;
        dfs(root);
        return result;
    }

    void dfs(TreeNode* root) {
        if(!root->left && !root->right) {
            string tmp = "";
            int size = cur.size(), i;
            for(i = 0; i < size; i++)
                tmp += to_string(cur[i]) + "->";
            tmp += to_string(root->val);
            result.push_back(tmp);
        }

        cur.push_back(root->val);
        if(root->left)
            dfs(root->left);
        if(root->right)
            dfs(root->right);
        cur.pop_back();
    }
};