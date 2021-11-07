//
// Created by BrandonZu on 10/5/21.
//

#include "common.h"
#include "ListNode.h"

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head, *fast = head;
        int cnt = 1;
        while(fast->next) {
            slow = slow->next;
            fast = fast->next, cnt++;
            if(fast->next)
                fast = fast->next, cnt++;
        }
        
    }
};
