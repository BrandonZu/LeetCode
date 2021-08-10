//
// Created by BrandonZu on 2021/8/10.
//

#include "common.h"
#include "ListNode.h"

// Runtime 8ms(>73%) | Memory Usage 15MB(>52%)
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!l1 || !l2) return !l1 ? l2 : l1;
        ListNode* dummy = new ListNode(-1), * tail = dummy;
        while(l1 && l2) {
            if(l1->val <= l2->val) {
                tail->next = l1;
                tail = l1;
                l1 = l1->next;
            }
            else {
                tail->next = l2;
                tail = l2;
                l2 = l2->next;
            }
        }
        tail->next = l1 ? l1 : l2;
        return dummy->next;
    }
};

