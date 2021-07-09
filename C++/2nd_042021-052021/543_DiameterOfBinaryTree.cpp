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
    int maxResult;
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root)
            return 0;
        maxResult = 0;
        postorder(root);
        return maxResult - 1;
    }

    int postorder(TreeNode* root) {
        if(!root) return 0;
        int leftMax = postorder(root->left);
        int rightMax = postorder(root->right);
        maxResult = max(maxResult, leftMax + rightMax + 1);
        return max(leftMax, rightMax) + 1;
    }
};

