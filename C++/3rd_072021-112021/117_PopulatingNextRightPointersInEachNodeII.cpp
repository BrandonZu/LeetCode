//
// Created by BrandonZu on 2021/7/4.
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

class Solution {
public:
    void dfs(Node* root) {
        if(!root)
            return;

        Node* l = root->left, * r = root->right;
        while(l && r) {
            l->next = r;
            l = l->right ? l->right : l->left;
            r = r->left ? r->left : r->right;
        }

        dfs(root->left);
        dfs(root->right);
    }

    Node* connect(Node* root) {
        dfs(root);
        return root;
    }
};

class Wrong_Solution {
public:
    Node* connect(Node* root) {
        if(!root) return root;
        Node* cur_start = root;
        while(cur_start->left) {
            Node* cur = cur_start;
            while(cur) {
                Node* next_node = cur;
                while(next_node && !next_node->left && !next_node->right)
                    next_node = next_node->next;

                if(cur->left && cur->right) {
                    cur->left->next = cur->right;
                    cur->right->next = next_node->left ? next_node->left : next_node->right;
                }
                else if(cur->left && !cur->right) {
                    cur->left->next = next_node->left ? next_node->left : next_node->right;
                }
                else if(!cur->left && cur->right){
                    cur->right->next = next_node->left ? next_node->left : next_node->right;
                }
                cur = next_node;
            }
            // 失败，无法知道下一层开头在哪
            cur_start = cur_start->left;
        }
        return root;
    }
};
