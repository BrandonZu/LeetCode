//
// Created by BrandonZu on 9/30/21.
//

#include "common.h"
#include "ListNode.h"

// Runtime 4ms(>55%) | Memory Usage 7.5MB(>15%)
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* pre = dummy, * next = dummy;
        ListNode* start = dummy, * end = dummy;
        for(int i = 0; i < left - 1; i++) pre = pre->next;
        start = pre->next;
        for(int i = 0; i < right; i++) end = end->next;
        next = end->next;

        ListNode* preNode = start, * curNode = start->next;
        while(preNode != end) {
            ListNode* nextNode = curNode->next;
            curNode->next = preNode;
            preNode = curNode;
            curNode = nextNode;
        }
        pre->next = end;
        start->next = next;
        return dummy->next;
    }
};


