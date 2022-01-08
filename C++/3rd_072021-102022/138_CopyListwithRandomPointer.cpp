//
// Created by BrandonZu on 2021/8/21.
//

#include "common.h"

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

// Runtime 23ms(>6.18%) | Memory Usage 11.3MB(26.7%)
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return nullptr;
        for(Node* cur = head; cur; cur = cur->next->next) {
            Node* node = new Node(cur->val);
            node->next = cur->next;
            cur->next = node;
        }

        for(Node* cur = head; cur; cur = cur->next->next) {
            if(cur->random)
                cur->next->random = cur->random->next;
        }

        Node* res = head->next;
        for(Node* cur = head, * next = cur; cur && next; cur = next) {
            next = cur->next->next;
            if(next)
                cur->next->next = next->next;
            cur->next = next;
        }
        return res;
    }
};

// Runtime 8ms(>75%) | Memory Usage 11.3MB(>26.7%)
class Solution_HashMap {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> nodeMap;

        Node* tmp = head, * pre = nullptr;
        while(tmp) {
            Node* node = new Node(tmp->val);
            if(pre)
                nodeMap[pre]->next = node;

            nodeMap[tmp] = node;

            pre = tmp;
            tmp = tmp->next;
        }

        tmp = head;
        while(tmp) {
            nodeMap[tmp]->random = nodeMap[tmp->random];
            tmp = tmp->next;
        }

        return nodeMap[head];
    }
};

// Runtime 8ms(>75%) | Memory Usage 11.2MB(>88%)
class Solution_R1 {
public:
    Node* copyRandomList(Node* head) {
        for(auto* p = head; p; p = p->next->next) {
            Node* tmp = new Node(p->val);
            tmp->next = p->next;
            p->next = tmp;
        }
        for(auto* p = head; p; p = p->next->next) {
            if(p->random) {
                p->next->random = p->random->next;
            }
        }
        Node* res = new Node(-1), * tail = res;
        auto* p = head;
        while(p) {
            Node* n_node = p->next->next;
            tail->next = p->next, tail = tail->next;
            p->next = n_node;
            p = n_node;
        }
        return res->next;
    }
};
