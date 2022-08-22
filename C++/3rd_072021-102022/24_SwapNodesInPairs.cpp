//
// Created by BrandonZu on 2021/7/17.
//

#include "ListNode.h"
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

// R .74 | M .55
class Solution2 {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next) {
            return head;
        }
        ListNode* dummy = new ListNode(-1, head);
        ListNode* prev = dummy;
        while(prev && prev->next && prev->next->next) {
            ListNode* cur = prev->next, * next = cur->next;
            cur->next = next->next;
            next->next = cur;
            prev->next = next;

            prev = cur;
        }
        return dummy->next;
    }
};