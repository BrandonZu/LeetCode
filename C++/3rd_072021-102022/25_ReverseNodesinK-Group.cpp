//
// Created by BrandonZu on 9/28/21.
//

#include "common.h"
#include "ListNode.h"

// Runtime 4ms(>100%) | Memory Usage 11.4MB(>70%)
class Solution {
public:
    void reverseList(ListNode* start) {
        ListNode* pre = start, * cur = start->next;
        while(cur) {
            ListNode* next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* pre = dummy, * start = head;
        while(start) {
            ListNode* end = start;
            for(int i = 0; i < k - 1 && end; i++) {
                end = end->next;
            }
            if(!end) break;
            ListNode* next = end->next;

            end->next = nullptr;
            reverseList(start);

            pre->next = end;
            start->next = next;
            pre = start, start = next;
        }
        return dummy->next;
    }
};
