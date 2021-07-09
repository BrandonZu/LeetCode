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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if(!root) return res;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int size = q.size();
            for(int i = 0; i < size - 1; i++) {
                TreeNode* node = q.front();
                q.pop();
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }
            // The rightmost node in this layer
            TreeNode* rightmostNode = q.front();
            q.pop();
            res.push_back(rightmostNode->val);
            if(rightmostNode->left)
                q.push(rightmostNode->left);
            if(rightmostNode->right)
                q.push(rightmostNode->right);
        }
        return res;
    }
};

