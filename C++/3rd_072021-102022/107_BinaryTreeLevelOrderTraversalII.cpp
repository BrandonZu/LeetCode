//
// Created by BrandonZu on 2021/7/2.
//

#include "iostream"
#include "vector"
#include "queue"
#include "algorithm"
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(): val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> result;
        if(!root) return result;
        queue<TreeNode*> myQueue;
        vector<int> curLv;
        myQueue.push(root);
        while(!myQueue.empty()) {
            curLv.clear();
            size_t size = myQueue.size();
            for(size_t i = 0; i < size; i++) {
                TreeNode* cur = myQueue.front();
                myQueue.pop();
                curLv.push_back(cur->val);
                if(cur->left) myQueue.push(cur->left);
                if(cur->right) myQueue.push(cur->right);
            }
            result.push_back(curLv);
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
