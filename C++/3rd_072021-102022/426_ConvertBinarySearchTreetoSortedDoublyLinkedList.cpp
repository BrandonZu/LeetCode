//
// Created by BrandonZu on 11/6/21.
//

#include "common.h"
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};

// Runtime 4ms(>90%) | Memory Usage 7.6MB(>81%)
class Solution {
    Node* prev;
public:
    void postorder(Node* root) {
        if(!root) return;
        postorder(root->left);
        root->left = prev;
        prev->right= root;
        prev = root;
        postorder(root->right);
    }

    Node* treeToDoublyList(Node* root) {
        if(!root) return root;
        Node* head = new Node(-1);
        prev = head;
        postorder(root);
        prev->right = head->right;
        head->right->left = prev;
        return head->right;
    }
};

// 1st Review 12/12/21
// Runtime 4ms(>90%) | Memory Usage 7.6MB(>81%)
class Solution_R1 {
    Node* prev;
public:
    void inorder(Node* root) {
        if(!root) return;
        inorder(root->left);
        root->left = prev;
        prev->right = root;
        prev = root;
        inorder(root->right);
    }

    Node* treeToDoublyList(Node* root) {
        if(!root) return root;
        Node* head = new Node(-1);
        prev = head;
        inorder(root);
        prev->right = head->right;
        head->right->left = prev;
        return head->right;
    }
};