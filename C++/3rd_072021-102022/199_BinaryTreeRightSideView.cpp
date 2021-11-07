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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        if(!root) return result;
        queue<TreeNode*> myQueue;
        myQueue.push(root);

        while(!myQueue.empty()) {

            result.push_back(myQueue.front()->val);

            int size = myQueue.size();
            for(int i = 0; i < size; i++) {
                TreeNode* cur = myQueue.front();
                myQueue.pop();
                if(cur->right) myQueue.push(cur->right);
                if(cur->left) myQueue.push(cur->left);
            }
        }

        return result;
    }
};
