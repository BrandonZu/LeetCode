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
    int maximum;
public:
    int maxPathSum(TreeNode* root) {
        maximum = INT_MIN;
        recurSum(root);
        return maximum;
    }

    int recurSum(TreeNode* root) {
        if(!root)
            return 0;
        // Postorder Traverse
        int left = max(0, recurSum(root->left));
        int right = max(0, recurSum(root->right));

        maximum = max(maximum, root->val + left + right);
        return max(left, right) + root->val;
    }
};
