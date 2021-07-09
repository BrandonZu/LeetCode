#include <stack>
#include <vector>
using namespace std;

struct TreeNode {
    TreeNode* left;
    TreeNode* right;
    int val;
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<pair<bool, TreeNode*>> mid;
        if(!root)
            return result;
        mid.push(make_pair(false, root));
        while(!mid.empty()) {
            auto& p = mid.top();
            if(!p.first) {
                p.first = true;
                if(p.second->left)
                    mid.push(make_pair(false, p.second->left));
            }
            else {
                result.push_back(p.second->val);
                TreeNode* tmp = p.second->right;
                mid.pop();
                if(p.second->right)
                    mid.push(make_pair(false, tmp));
            }
        }
        return result;
    }
};