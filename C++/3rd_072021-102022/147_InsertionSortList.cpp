//
// Created by BrandonZu on 1/18/22.
//

#include "common.h"
#include "ListNode.h"

// Runtime 73ms(>20%) | Memory Usage 9.5MB(>96%)
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode* dummy = new ListNode(-1);
        ListNode* origin = head;
        while(origin) {
            ListNode* prev = dummy, * cur = dummy->next;
            while(cur && cur->val < origin->val) {
                prev = cur;
                cur = cur->next;
            }
            ListNode* tmp = origin->next;
            prev->next = origin;
            origin->next = cur;
            origin = tmp;
        }
        return dummy->next;
    }
};
