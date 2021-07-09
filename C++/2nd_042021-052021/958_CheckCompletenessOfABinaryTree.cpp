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
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> q;
        if(!root)
            return true;
        q.push(root);
        bool mustBeNull = false;
        while(!q.empty()) {
            int size = q.size();
            int i = 0;
            while(i < size) {
                TreeNode* cur = q.front();
                q.pop();
                i++;
                if(cur) {
                    if(mustBeNull)
                        return false;
                    q.push(cur->left);
                    q.push(cur->right);
                }
                else {
                    mustBeNull = true;
                }
            }
        }
        return true;
    }
};

