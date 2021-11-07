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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> result;
        queue<TreeNode*> myQueue;
        if(!root) return result;
        myQueue.push(root);
        while(!myQueue.empty()) {
            int size = myQueue.size();
            double sum = 0;
            for(int i = 0; i < size; i++) {
                TreeNode* cur = myQueue.front();
                myQueue.pop();
                sum += cur->val;
                if(cur->left) myQueue.push(cur->left);
                if(cur->right) myQueue.push(cur->right);
            }
            result.push_back(sum / size);
        }

        return result;
    }
};

