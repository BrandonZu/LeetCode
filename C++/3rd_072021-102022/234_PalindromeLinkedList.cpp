//
// Created by BrandonZu on 10/5/21.
//

#include "common.h"
#include "ListNode.h"

// Runtime 218ms(>48%) | Memory Usage 110MB(>98%)
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(!head) return true;
        ListNode* slow = head, *fast = head;
        ListNode* pre = nullptr;
        while(fast && fast->next) {
            fast = fast->next->next;

            ListNode* next = slow->next;
            slow->next = pre;
            pre = slow;
            slow = next;
        }
        ListNode* l = pre;
        ListNode* r = fast ? slow->next : slow;
        while(l && r) {
            if(l->val != r->val)
                return false;
            l = l->next, r = r->next;
        }
        return true;
    }
};
