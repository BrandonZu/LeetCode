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
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        if(!root->left && !root->right) return 1;
        int tmp = INT_MAX;
        if(root->left)
            tmp = min(tmp, minDepth(root->left));
        if(root->right)
            tmp = min(tmp, minDepth(root->right));
        return tmp + 1;
    }
};
