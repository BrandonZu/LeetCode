//
// Created by BrandonZu on 2021/7/17.
//

#include "common.h"
#include "ListNode.h"

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

// Runtime 40ms(>42%) | Memory Usage 15MB(>49%)
class Solution2 {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummy = new ListNode(-1), * tail = dummy;
        while(head) {
            if(head->val != val) {
                tail->next = head;
                tail = head;
            }
            head = head->next;
        }
        tail->next = nullptr;
        return dummy->next;
    }
};
