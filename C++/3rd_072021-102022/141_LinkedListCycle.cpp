//
// Created by BrandonZu on 2021/7/17.
//

#include "common.h"
#include "ListNode.h"

// Runtime 4ms(>100%) | Memory Usage 7.8MB(>96%)
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow = head, * fast = head;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast)
                return true;
        }
        return false;
    }
};