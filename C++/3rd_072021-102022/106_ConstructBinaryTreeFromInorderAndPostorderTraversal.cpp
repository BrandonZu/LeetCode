//
// Created by BrandonZu on 2021/7/11.
//

#include "common.h"
#include "TreeNode.h"

// Runtime 20ms(>66%) | Memory Storage 26MB(>85%)
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.empty() || postorder.empty())
            return nullptr;
        return recurBuild(postorder, inorder, 0, postorder.size() - 1, 0, inorder.size() - 1);
    }

    TreeNode* recurBuild(vector<int>& postorder, vector<int>& inorder, int post_l, int post_r, int in_l, int in_r) {
        if(post_l > post_r)
            return nullptr;
        else if(post_l == post_r)
            return new TreeNode(postorder[post_l]);
        int pos = find(inorder.begin() + in_l, inorder.begin() + in_r, postorder[post_r]) - inorder.begin();
        TreeNode* root = new TreeNode(postorder[post_r]);
        root->right = recurBuild(postorder, inorder, post_r - (in_r - pos), post_r - 1, pos + 1, in_r);
        root->left = recurBuild(postorder, inorder, post_l, post_r - (in_r - pos) - 1, in_l, pos - 1);
        return root;
    }
};

// R .31 | M .75
class Solution2 {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return helper(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
    }

    TreeNode* helper(vector<int>& in, int inL, int inR, vector<int>& post, int postL, int postR) {
        if(inL > inR || postL > postR) {
            return nullptr;
        }
        int mid;
        for(mid = inL; mid < inR; mid++) {
            if(in[mid] == post[postR]) {
                break;
            }
        }
        int lSize = mid - inL, rSize = inR - mid;
        TreeNode* root = new TreeNode(post[postR]);
        root->left = helper(in, inL, mid - 1, post, postL, postL + lSize - 1);
        root->right = helper(in, mid + 1, inR, post, postR - 1 - rSize + 1 , postR - 1);
        return root;
    }
};