#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return recurBuild(preorder, inorder, 0, 0, inorder.size() - 1);
    }

    TreeNode* recurBuild(vector<int>& preorder, vector<int>& inorder, int pre, int in_left, int in_right) {
        if(in_left == in_right) {
            return new TreeNode(inorder[in_left]);
        }
        if(in_left > in_right) return nullptr;
        int cur = preorder[pre];
        TreeNode* root = new TreeNode(cur);
        int pos = find(inorder.begin() + in_left, inorder.begin() + in_right + 1, cur) - inorder.begin();
        int left_size = pos - in_left;
        root->left = recurBuild(preorder, inorder, pre + 1, in_left, pos - 1);
        root->right = recurBuild(preorder, inorder, pre + 1 + left_size, pos + 1, in_right);
        return root;
    }
};

