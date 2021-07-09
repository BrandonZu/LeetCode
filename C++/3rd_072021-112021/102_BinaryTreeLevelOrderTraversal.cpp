//
// Created by BrandonZu on 2021/7/2.
//

#include "iostream"
#include "vector"
#include "queue"
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(!root) return result;
        queue<TreeNode*> myQueue;
        myQueue.push(root);

        vector<int> curLevel;
        while(!myQueue.empty()) {
            curLevel.clear();
            int size = myQueue.size();
            for(int i = 0; i < size; i++) {
                TreeNode* cur = myQueue.front();
                curLevel.push_back(cur->val);
                myQueue.pop();
                if(cur->left)
                    myQueue.push(cur->left);
                if(cur->right)
                    myQueue.push(cur->right);
            }
            result.push_back(curLevel);
        }

        return result;
    }
};
