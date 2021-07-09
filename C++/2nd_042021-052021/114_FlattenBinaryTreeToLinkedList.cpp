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
    TreeNode* pre;
public:
    void flatten(TreeNode* root) {
        if(!root) return;
        TreeNode* cur_left = root->left, * cur_right = root->right;
        if(pre) {
            pre->right = root;
            pre->left = nullptr;
        }
        pre = root;
        flatten(cur_left);
        flatten(cur_right);
    }
};

