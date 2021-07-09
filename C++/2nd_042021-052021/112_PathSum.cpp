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
    int target;
    int cur;
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        flag = false;
        this->target = targetSum;
        if(!root) return false;
        recur(root);
        return flag;
    }

    void recur(TreeNode* root) {
        if(flag) return;
        if(!root->left && !root->right) {
            cur += root->val;
            if(cur == target)
                flag = true;
            cur -= root->val;
            return;
        }
        cur += root->val;
        if(root->left)
            recur(root->left);
        if(root->right)
            recur(root->right);
        cur -= root->val;
    }
};

