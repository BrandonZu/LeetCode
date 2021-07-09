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
    vector<vector<int>> ans;
    int target;
public:
    void recur(TreeNode* root) {
        if(!root)
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
                ans.push_back(cur);
        }
        cur.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        target = sum;
        recur(root);
        return ans;
    }
};
