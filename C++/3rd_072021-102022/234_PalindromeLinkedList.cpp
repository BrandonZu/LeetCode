//
// Created by BrandonZu on 10/5/21.
//

#include "common.h"
#include "ListNode.h"

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head, *fast = head;
        ListNode* pre = slow;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* l1 = head;
        ListNode* l2 =
    }
};
