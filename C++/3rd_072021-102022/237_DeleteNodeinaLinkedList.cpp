//
// Created by BrandonZu on 2/17/22.
//

#include "common.h"
#include "ListNode.h"

// Runtime 24ms(>23%) | Memory Usage 7.6MB(>73%)
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* tmp = node->next;
        *node = *node->next;
        delete tmp;
    }
};
