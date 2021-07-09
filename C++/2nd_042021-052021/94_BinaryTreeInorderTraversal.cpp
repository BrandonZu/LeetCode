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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        recur(root, result);
        return result;
    }
    void recur(TreeNode* root, vector<int>& result) {
        if(!root)
            return;
        recur(root->left, result);
        result.push_back(root->val);
        recur(root->right, result);
    }
};
