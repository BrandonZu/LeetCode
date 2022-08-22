//
// Created by BrandonZu on 2021/7/17.
//

#include "common.h"
#include "ListNode.h"

// Runtime 4ms(>83%) | Memory Usage 10.6MB(>72%)
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* next = dummy;
        for(int i = 0; i < n; i++) {
            next = next->next;
        }
        ListNode* pre = dummy, * cur = dummy->next;
        while(next->next) {
            pre = cur;
            cur = cur->next;
            next = next->next;
        }
        pre->next = cur->next;
        delete cur;
        return dummy->next;
    }
};

// R .45 | M .75
class Solution2 {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(-1, head);
        ListNode* slow = dummy, * fast = dummy, * prev = nullptr;
        for(int i = 0; i < n; i++) {
            fast = fast->next;
        }
        while(fast) {
            prev = slow;
            slow = slow->next;
            fast = fast->next;
        }
        prev->next = slow->next;
        delete slow;
        ListNode* ret = dummy->next;
        delete dummy;
        return ret;
    }
};