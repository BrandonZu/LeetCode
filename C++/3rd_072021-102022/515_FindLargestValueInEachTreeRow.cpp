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
    vector<int> largestValues(TreeNode* root) {
        vector<int> result;
        if(!root) return result;
        queue<TreeNode*> myQueue;
        myQueue.push(root);

        int max_num = INT_MIN;
        while(!myQueue.empty()) {
            int size = myQueue.size();
            max_num = INT_MIN;
            for(int i = 0; i < size; i++) {
                TreeNode* cur = myQueue.front();
                myQueue.pop();
                max_num = max(max_num, cur->val);
                if(cur->left) myQueue.push(cur->left);
                if(cur->right) myQueue.push(cur->right);
            }
            result.push_back(max_num);
        }
        return result;
    }
};