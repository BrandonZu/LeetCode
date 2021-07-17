//
// Created by BrandonZu on 2021/7/17.
//

#include "stl.h"
#include "LinkedListNode.h"

// Runtime 20ms(>83%) | Memory Cost 15MB(>78%)
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* pre = dummy, * cur = head;
        while(cur) {
            if(cur->val == val) {
                pre->next = cur->next;
                cur = pre->next;
            }
            else {
                pre = cur;
                cur = cur->next;
            }
        }

        return dummy->next;
    }
};


