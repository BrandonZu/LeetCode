//
// Created by BrandonZu on 10/1/21.
//

#include "common.h"
#include "ListNode.h"

// Runtime 8ms(>64%) | Memory Usage 11.7MB(>53%)
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr) return head;
        int len = 0;
        for(ListNode* tmp = head; tmp; tmp = tmp->next) {
            len++;
        }
        k = k % len;
        if(k == 0) return head;

        ListNode* start = head, *end = head;
        for(int i = 0; i < k; i++) {
            end = end->next;
        }
        // Start points to the k+1 th number from the bottom of the list
        while(end->next != nullptr) {
            start = start->next;
            end = end->next;
        }
        ListNode* newHead = start->next;
        start->next = nullptr;
        end->next = head;
        return newHead;
    }
};
