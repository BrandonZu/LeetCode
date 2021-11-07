//
// Created by BrandonZu on 11/4/21.
//

#include "common.h"

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};

// Runtime 12ms(>88%) | Memory Usage 10MB(>48%)
class Solution {
public:
    Node* lowestCommonAncestor(Node* p, Node * q) {
        int depth_p = 0, depth_q = 0;
        Node* tmp = p;
        while(tmp) {
            depth_p++;
            tmp = tmp->parent;
        }
        tmp = q;
        while(tmp) {
            depth_q++;
            tmp = tmp->parent;
        }
        if(depth_p > depth_q) {
            for(int i = 0; i < depth_p - depth_q; i++) {
                p = p->parent;
            }
        }
        else {
            for(int i = 0; i < depth_q - depth_p; i++) {
                q = q->parent;
            }
        }
        while(p != q) {
            p = p->parent, q = q->parent;
        }
        return p;
    }
};
