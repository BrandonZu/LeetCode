//
// Created by BrandonZu on 2021/7/14.
//

#include "common.h"
#include "TreeNode.h"

// Timecost 4ms(>99%) | Memory Cost 21.3MB(>77%)
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.empty()) return nullptr;
        return recur(nums, 0, nums.size() - 1);
    }

    TreeNode* recur(vector<int>& nums, int left, int right) {
        if(left > right)
            return nullptr;
        else if(left ==  right)
            return new TreeNode(nums[left]);

        int mid = (left + right) >> 1;
        auto* root = new TreeNode(nums[mid]);
        root->left = recur(nums, left, mid - 1);
        root->right = recur(nums, mid+1, right);
        return root;
    }
};

// 1st Review 11/5/21
// Runtime 12ms(>80%) | Memory Usage 21MB(>77%)
class Solution_R1 {
public:
    TreeNode* buildBST(vector<int>& nums, int l, int r) {
        if(l > r) return nullptr;
        if(l == r) return new TreeNode(nums[l]);

        int mid = (l + r) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = buildBST(nums, l, mid - 1);
        root->right = buildBST(nums, mid + 1, r);
        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return buildBST(nums, 0, nums.size() - 1);
    }
};

