//
// Created by BrandonZu on 2021/9/1.
//

#include "common.h"
#include "ListNode.h"

// Runtime 12ms(>18%) | Memory Usage 11MB(>91%)
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* pre = dummy;
        while(pre->next) {
            ListNode* cur = pre->next;
            ListNode* next = cur->next;
            while(next && next->val == cur->val)
                next = next->next;

            if(next != cur->next) {
                // Remove Duplicate Numbers
                pre->next = next;
            }
            else {
                pre = cur;
            }
        }
        return dummy->next;
    }
};

