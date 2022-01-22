//
// Created by BrandonZu on 1/21/22.
//

#include "common.h"

class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};

// Runtime 0ms(>100%) | Memory Usage 7.4MB(>63%)
class Solution {
public:
    Node* recur(Node* head) {
        Node* prev = nullptr, * cur = head;
        while(cur) {
            if(!cur->child) {
                prev = cur;
                cur = cur->next;
                continue;
            }
            Node* next = cur->next;

            cur->next = cur->child;
            cur->child->prev = cur;
            cur->child = nullptr;

            Node* tail = recur(cur->next);
            tail->next = next;
            if(next)
                next->prev = tail;

            prev = tail;
            cur = next;
        }
        return prev;
    }

    Node* flatten(Node* head) {
        if(!head) return head;
        recur(head);
        return head;
    }
};

