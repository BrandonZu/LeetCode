//
// Created by BrandonZu on 2021/9/3.
//

#include "common.h"
#include "ListNode.h"

// Runtime 11ms(>9%) | Memory Usage 10.2MB(>94%)
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* l = new ListNode(-1);
        ListNode* r = new ListNode(-1);
        ListNode* l_tail = l, * r_tail = r;
        ListNode* cur = head;
        while(cur) {
            if(cur->val < x) {
                l_tail->next = cur;
                l_tail = cur;
            }
            else {
                r_tail->next = cur;
                r_tail = cur;
            }
            cur = cur->next;
        }
        l_tail->next = r->next;
        r_tail->next = nullptr;
        delete r;
        return l->next;
    }
};

// R .87 | M .94
class Solution2 {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* dummy1 = new ListNode(-1, nullptr), *tail1 = dummy1;
        ListNode* dummy2 = new ListNode(-1, nullptr), *tail2 = dummy2;
        while(head) {
            if(head->val < x) {
                tail1->next = head;
                tail1 = tail1->next;
            }
            else {
                tail2->next = head;
                tail2 = tail2->next;
            }
            head = head->next;
        }
        tail1->next = dummy2->next;
        tail2->next = nullptr;
        return dummy1->next;
    }
};