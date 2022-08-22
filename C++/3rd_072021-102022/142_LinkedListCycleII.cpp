//
// Created by BrandonZu on 2021/7/17.
//

#include "ListNode.h"
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

// R .64 | M .38
class Solution2 {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head, * fast = head;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) {
                break;
            }
        }
        if(!fast || !fast->next) {
            return nullptr;
        }
        else {
            slow = head;
            while(slow != fast) {
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
    }
};