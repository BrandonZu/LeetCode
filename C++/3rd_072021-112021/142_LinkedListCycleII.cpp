//
// Created by BrandonZu on 2021/7/17.
//

#include "LinkedListNode.h"
#include "common.h"

// Runtime 4ms(>100%) | Memory Usage 7.5MB(>90%)
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head, * fast = head;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) {
                slow = head;
                while(fast != slow) {
                    fast = fast->next;
                    slow = slow->next;
                }
                return slow;
            }
        }
        return nullptr;
    }
};