#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
};

class Solution {
    vector<int> cur;
    bool flag;
    int target;
public:
    void recur(TreeNode* root) {
        if(!root || flag)
            return;
        cur.push_back(root->val);
        if(root->left)
            recur(root->left);
        if(root->right)
            recur(root->right);
        if(!root->left && !root->right) {
            int count = 0;
            for(auto num: cur)
                count += num;
            if(count == target)
                flag = true;
        }
        cur.pop_back();
    }

    bool hasPathSum(TreeNode* root, int sum) {
        flag = false;
        target = sum;
        recur(root);
        return flag;
    }
};
