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