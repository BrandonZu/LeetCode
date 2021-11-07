//
// Created by BrandonZu on 2021/7/13.
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

// Runtime 20ms(>68%) | Memory Cost 24MB(>76%)
class Solution {
    vector<int> result;
    int curMost = 0;
    int curCount = 0;
    TreeNode* preNode = nullptr;
public:
    vector<int> findMode(TreeNode* root) {
        if(!root) return result;
        inorder(root);
        return result;
    }

    void inorder(TreeNode* root) {
        if(root->left)
            inorder(root->left);

        if(!preNode) {
            curCount = 1;
            curMost = 1;
            result.push_back(root->val);
        }
        else if(preNode->val == root->val) {
            curCount++;
            if(curCount == curMost) {
                result.push_back(root->val);
            }
            else if(curCount > curMost) {
                result.clear();
                curMost = curCount;
                result.push_back(root->val);
            }
        }
        else {
            curCount = 1;
            if(curCount == curMost) {
                result.push_back(root->val);
            }
        }
        preNode = root;

        if(root->right)
            inorder(root->right);
    }
};
