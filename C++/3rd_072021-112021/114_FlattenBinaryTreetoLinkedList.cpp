//
// Created by BrandonZu on 2021/7/14.
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

// Runtime 4ms(>88%) | Memory Usage 12.7MB(>73%)
class Solution {
    TreeNode* preNode;
public:
    void flatten(TreeNode* node) {
        if(!node) return;
        preNode = nullptr;
        preorder(node);
        auto* cur = node;
        while(cur) {
            cur->right = cur->left;
            cur->left = nullptr;
            cur = cur->right;
        }
    }

    void preorder(TreeNode* root) {
        if(preNode)
            preNode->left = root;
        preNode = root;
        if(root->left)
            preorder(root->left);
        if(root->right)
            preorder(root->right);
    }
};

int main() {
    auto* root = new TreeNode(0);
    root->left = new TreeNode(1);
    root->right = new TreeNode(2);
    Solution test;
    test.flatten(root);

}