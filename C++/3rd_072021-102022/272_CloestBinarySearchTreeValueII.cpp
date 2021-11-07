//
// Created by BrandonZu on 10/16/21.
//

#include "common.h"
#include "TreeNode.h"


// Runtime 12ms(>78%) | Memory Usage 21.4MB(>94%)
class Solution_MaxHeap {
public:
    static double target;
    struct myCmp {
        bool operator() (const int& a, const int& b) {
            return abs(a - target) < abs(b - target);
        }
    };

    priority_queue<int, vector<int>, myCmp> max_heap;

    void inorder(TreeNode* root, int k) {
        if(!root) return;
        inorder(root->left, k);
        max_heap.push(root->val);
        if(max_heap.size() > k)
            max_heap.pop();
        inorder(root->right, k);
    }

    vector<int> closestKValues(TreeNode* root, double target, int k) {
        Solution_MaxHeap::target = target;
        vector<int> res;
        inorder(root, k);
        while(!max_heap.empty()) {
            res.push_back(max_heap.top());
            max_heap.pop();
        }
        return res;
    }
};