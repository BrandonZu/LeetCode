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
    int countNodes(TreeNode* root) {
        int count = 0;
        recur(root, count);
        return count;
    }

    void recur(TreeNode* root, int& count) {
        if(!root)
            return;
        count++;
        recur(root->left, count);
        recur(root->right, count);
    }
};
