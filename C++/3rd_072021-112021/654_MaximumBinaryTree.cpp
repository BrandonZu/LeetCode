//
// Created by BrandonZu on 2021/7/13.
//

#include "common.h"
#include "TreeNode.h"

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

// Runtime 68ms(>93%) | Memory Cost 42.7MB(>35%)
class Solution_R1 {
public:
    TreeNode* helper(vector<int>& nums, int l, int r) {
        if(l > r)
            return nullptr;
        if(l == r)
            return new TreeNode(nums[l]);
        int max_index = l;
        for(int i = l + 1; i <= r; i++) {
            if(nums[i] > nums[max_index])
                max_index = i;
        }
        TreeNode* root = new TreeNode(nums[max_index]);
        root->left = helper(nums, l, max_index - 1);
        root->right = helper(nums, max_index + 1, r);
        return root;
    }

    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if(nums.empty())
            return nullptr;
        TreeNode* root = helper(nums, 0, nums.size() - 1);
        return root;
    }
};
