//
// Created by BrandonZu on 11/27/21.
//

#include "common.h"

class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};

// Runtime 8ms(>76%) | Memory Usage 8.1MB(>61%)
class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        Node* new_node = new Node(insertVal);
        if(!head) {
            new_node->next = new_node;
            return new_node;
        }

        Node* cur = head->next, * prev = head;
        bool inserted = false;
        do {
            if(prev->val <= insertVal && cur->val >= insertVal || prev->val > cur->val && (cur->val >= insertVal || insertVal >= prev->val))  {
                prev->next = new_node;
                new_node->next = cur;
                inserted = true;
                break;
            }
            prev = cur;
            cur = cur->next;
        } while(prev != head);
        if(!inserted) {
            prev->next = new_node;
            new_node->next = cur;
        }
        return head;
    }
};
