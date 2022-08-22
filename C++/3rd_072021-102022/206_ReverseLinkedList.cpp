#include "common.h"
#include "ListNode.h"

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* pre = nullptr, * cur = head;
        while(cur) {
            ListNode* next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }
};

// R .47 | M .98
class Solution2 {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr, * cur = head;
        while(cur) {
            ListNode* next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }
};
