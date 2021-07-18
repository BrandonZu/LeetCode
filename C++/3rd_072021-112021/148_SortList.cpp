//
// Created by BrandonZu on 2021/7/18.
//

#include "common.h"
#include "ListNode.h"

// Runtime 92ms(>60%) | Memory Usage 48.6MB(>23%2)
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;

        ListNode* slow = head, * fast = head;
        while(fast && fast->next) {
            fast = fast->next;
            if(!fast->next) break;
            fast = fast->next;
            slow = slow->next;
        }
        ListNode* next = slow->next;
        slow->next = nullptr;
        auto* i = sortList(head);
        auto* j = sortList(next);

        ListNode* dummy = new ListNode(-1);
        ListNode* tail = dummy;
        while(i && j) {
            if(i->val < j->val) {
                tail->next = i;
                i = i->next;
            }
            else {
                tail->next = j;
                j = j->next;
            }
            tail = tail->next;
        }
        if(i)
            tail->next = i;
        if(j)
            tail->next = j;
        return dummy->next;
    }
};