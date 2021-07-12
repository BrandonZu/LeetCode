//
// Created by BrandonZu on 2021/7/11.
//

#include "vector"
#include "unordered_map"
#include "algorithm"
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(): val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Runtime 4ms(>99%) | Memory Usage 25.8MB(>36%)
class Solution {
    unordered_map<int, int> post_map;
public:
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        for(int i = 0; i < post.size(); i++) {
            post_map[post[i]] = i;
        }
        return recur(pre, post, 0, pre.size() - 1, 0, post.size() - 1);
    }

    TreeNode* recur(vector<int>& pre, vector<int>& post, int pre_l, int pre_r, int post_l, int post_r) {
        if(pre_l > pre_r)
            return nullptr;
        else if(pre_r == pre_l)
            return new TreeNode(pre[pre_l]);

        TreeNode* root = new TreeNode(pre[pre_l]);
        int pos = post_map[pre[pre_l + 1]];
        int l_num = pos - post_l + 1;
        root->left = recur(pre, post, pre_l + 1, pre_l + l_num, post_l, pos);
        root->right = recur(pre, post, pre_l + l_num + 1, pre_r, pos + 1, post_r - 1);

        return root;
    }
};