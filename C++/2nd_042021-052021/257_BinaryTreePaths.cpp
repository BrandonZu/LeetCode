#include <vector>
#include <queue>
#include <string>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
};

class Solution {
    vector<string> result;
    string cur;
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        recur(root);
        return result;
    }

    void recur(TreeNode* root) {
        if(!root) return;
        string pre = cur;
        if(!cur.empty())
            cur = cur + "->" + to_string(root->val);
        else
            cur = to_string(root->val);
        if(!root->left && !root->right) {
            result.push_back(cur);
        }
        else {
            if (root->left)
                recur(root->left);
            if (root->right)
                recur(root->right);
        }
        // Roll Back
        cur = pre;
        return;
    }
};
