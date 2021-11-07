//
// Created by BrandonZu on 9/19/21.
//

#include "common.h"
#include "ListNode.h"

// Runtime 20ms(>11%) | Memory Usage 11.5MB(>98%)
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* cur = head;
        while(cur) {
            // Remove all duplicates of current node
            ListNode* next = cur->next;
            while(next && next->val == cur->val)
                next = next->next;
            cur->next = next;
            cur = cur->next;
        }
        return head;
    }
};

