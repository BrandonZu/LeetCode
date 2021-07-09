#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        recur(root, res);
        return res;
    }

    void recur(TreeNode* root, vector<int>& res) {
        if(!root) return;
        res.push_back(root->val);
        recur(root->left, res);
        recur(root->right, res);
    }
};

