//
// Created by BrandonZu on 1/10/22.
//

#include "ListNode.h"

// Runtime 68ms(>14%) | Memory Usage 17.7MB(>75%)
class Solution {
public:
    void reorderList(ListNode* head) {
        ListNode* slow = head, * fast = head;
        while(fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        // Reverse the second half of the linked list
        ListNode* cur = slow->next, * prev = nullptr;
        slow->next = nullptr;
        while(cur) {
            ListNode* next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        // Insert
        ListNode* rev_head = prev;
        while(head && rev_head) {
            ListNode* rev_next = rev_head->next;
            rev_head->next = head->next;
            head->next = rev_head;

            rev_head = rev_next;
            head = head->next->next;
        }
    }
};
