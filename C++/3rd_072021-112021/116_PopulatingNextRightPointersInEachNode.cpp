//
// Created by BrandonZu on 2021/7/2.
//

#include "vector"
#include "queue"
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
            : val(_val), left(_left), right(_right), next(_next) {}
};

// BFS Time Complexity O(n); Space Complexity O(1)
class Solution_BFS_1 {
public:
    Node* connect(Node* root) {
        if(!root) return root;
        Node* cur_start = root;
        while(cur_start->left) {
            Node* cur = cur_start;
            while(cur) {
                cur->left->next = cur->right;
                if(cur->next)
                    cur->right->next = cur->next->left;
                else
                    cur->right->next = nullptr;
                cur = cur->next;
            }
            // Move to next level
            cur_start = cur_start->left;
        }
        return root;
    }
};

// BFS Using Queue Time Complexity O(n); Space Complexity O(n)
class Solution_BFS_2 {
public:
    Node* connect(Node* root) {
        if(!root) return root;
        queue<Node*> myQueue;
        myQueue.push(root);
        while(!myQueue.empty()) {
            int size = myQueue.size();

            for(int i = 0; i < size; i++) {
                Node* cur = myQueue.front();
                myQueue.pop();
                if(i != size - 1)
                    cur->next = myQueue.front();
                if(cur->left) myQueue.push(cur->left);
                if(cur->right) myQueue.push(cur->right);
            }
        }

        return root;
    }
};

// DFS Time Complexity O(n) Space Complexity O(1)
class Solution_DFS {
public:
    void dfs(Node* root) {
        if(!root) return;
        Node* l = root->left, * r = root->right;
        // Link the left subtree to the right subtree
        while(l && r) {
            l->next = r;
            l = l->right;
            r = r->left;
        }
        // Recursively link the left and right subtree
        dfs(root->left);
        dfs(root->right);
    }

    Node* connect(Node* root) {
        dfs(root);
        return root;
    }
};