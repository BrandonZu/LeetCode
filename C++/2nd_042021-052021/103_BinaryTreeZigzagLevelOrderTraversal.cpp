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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) return res;
        deque<TreeNode*> q;
        q.push_back(root);
        bool reverse = false;
        while(!q.empty()) {
            vector<int> cur;
            int size = q.size();
            for(int i = 0; i < size; i++) {
                if(!reverse) {
                    TreeNode* node = q.front();
                    q.pop_front();
                    cur.push_back(node->val);
                    if(node->left)
                        q.push_back(node->left);
                    if(node->right)
                        q.push_back(node->right);
                }
                else {
                    TreeNode* node = q.back();
                    q.pop_back();
                    cur.push_back(node->val);
                    if(node->right)
                        q.push_front(node->right);
                    if(node->left)
                        q.push_front(node->left);
                }
            }
            res.push_back(cur);
            reverse = !reverse;
        }
        return res;
    }
};
