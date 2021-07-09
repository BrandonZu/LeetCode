#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return getDepth(root) == -1 ? false : true;
    }

    int getDepth(TreeNode* root) {
        if(!root)
            return 0;
        int leftDepth = getDepth(root->left);
        if(leftDepth == -1) return -1;
        int rightDepth = getDepth(root->right);
        if(rightDepth == -1) return -1;
        if(abs(leftDepth - rightDepth) > 1) return -1;
        return max(leftDepth, rightDepth) + 1;
    }
};
