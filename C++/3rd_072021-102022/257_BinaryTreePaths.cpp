//
// Created by BrandonZu on 2021/7/5.
//

#include "common.h"
#include "TreeNode.h"

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

// R .63 | M .95
class Solution3 {
public:
    vector<string> res;
    vector<string> binaryTreePaths(TreeNode* root) {
        if(!root) return {};
        vector<TreeNode*> path;
        helper(root, path);
        return res;
    }

    void helper(TreeNode* root, vector<TreeNode*>& path) {
        path.push_back(root);
        if(!root->left && !root->right) {
            res.push_back(pathToStr(path));
        }
        if(root->left)
            helper(root->left, path);
        if(root->right)
            helper(root->right, path);
        path.pop_back();
    }

    string pathToStr(const vector<TreeNode*>& path) {
        string str;
        str = to_string(path[0]->val);
        for(int i = 1; i < path.size(); i++) {
            str.append("->" + to_string(path[i]->val));
        }
        return str;
    }
};