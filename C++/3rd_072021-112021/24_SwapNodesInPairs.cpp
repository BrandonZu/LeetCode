//
// Created by BrandonZu on 2021/7/17.
//

#include "LinkedListNode.h"
#include "common.h"

// Runtime 4ms(>63%) | Memory Cost 7.7MB(>5%)
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* cur = dummy;
        while(cur && cur->next && cur->next->next) {
            ListNode* left = cur->next, * right=  cur->next->next;
            left->next = right->next;
            right->next = left;
            cur->next = right;

            cur = cur->next->next;
        }
        return dummy->next;
    }
};
