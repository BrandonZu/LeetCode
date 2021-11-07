//
// Created by BrandonZu on 2021/7/2.
//

#include "iostream"
#include "vector"
#include "queue"
#include "algorithm"
using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> result;
        queue<Node*> myQueue;
        if(!root) return result;
        myQueue.push(root);
        vector<int> curLv;
        while(!myQueue.empty()) {
            curLv.clear();
            int size = myQueue.size();
            for(int i = 0; i < size; i++) {
                Node* cur = myQueue.front();
                myQueue.pop();
                curLv.push_back(cur->val);
                for(Node* n : cur->children)
                    if(n)
                        myQueue.push(n);
            }
            result.push_back(curLv);
        }
        return result;
    }
};