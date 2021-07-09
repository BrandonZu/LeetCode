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
    bool flag;
    TreeNode* pre;
public:
    bool isValidBST(TreeNode* root) {
        flag = true;
        pre = nullptr;
        inorderTraverse(root);
        return flag;
    }

    void inorderTraverse(TreeNode* root) {
        if(!root || !flag)
            return;
        inorderTraverse(root->left);
        if(pre && pre->val >= root->val) {
            flag = false;
            return;
        }
        pre = root;
        inorderTraverse(root->right);
    }
};
