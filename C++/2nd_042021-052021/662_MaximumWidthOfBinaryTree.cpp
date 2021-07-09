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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root)
            return 0;
        queue<pair<TreeNode*, int>> q;
        q.push(make_pair(root, 1));
        int maxWidth = 0;
        while(!q.empty()) {
            int size = q.size();
            int left = q.front().second;
            int right = q.back().second;
            maxWidth = max(maxWidth, right - left + 1);
            for(int i = 0; i < size; i++) {
                pair<TreeNode*, int> node_pair = q.front();
                q.pop();
                if(node_pair.first->left) {
                    q.push(make_pair(node_pair.first->left, (node_pair.second - left) * 2));
                }
                if(node_pair.first->right) {
                    q.push(make_pair(node_pair.first->right, (node_pair.second - left) * 2 + 1));
                }
            }
        }
        return maxWidth;
    }
};
