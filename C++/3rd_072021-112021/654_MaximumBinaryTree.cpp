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

// Runtime 68ms(>93%) | Memory Cost 42.7MB(>35%)
class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if(nums.empty()) return nullptr;
        return recursive(nums, 0, nums.size() - 1);
    }

    TreeNode* recursive(vector<int>& nums, int left, int right) {
        if(left > right)
            return nullptr;
        else if(left == right)
            return new TreeNode(nums[left]);

        int pos = left, maxVal = nums[left];
        for(int i = left; i <= right; i++) {
            if(nums[i] > maxVal) {
                pos = i;
                maxVal = nums[i];
            }
        }

        TreeNode* root = new TreeNode(maxVal);
        root->left = recursive(nums, left, pos - 1);
        root->right = recursive(nums, pos + 1, right);
        return root;
    }
};
