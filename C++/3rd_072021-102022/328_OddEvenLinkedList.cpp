//
// Created by BrandonZu on 1/21/22.
//

#include "common.h"
#include "ListNode.h"

// Runtime 8ms(>91%) | Memory Usage 10.6MB(>7%)
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        ListNode* odd = new ListNode(-1), * odd_tail = odd;
        ListNode* even = new ListNode(-1), * even_tail = even;
        ListNode* cur = head;
        int cnt = 0;
        while(cur) {
            cnt++;
            if(cnt % 2 == 1) {
                odd_tail->next = cur;
                odd_tail = odd_tail->next;
            }
            else {
                even_tail->next = cur;
                even_tail = even_tail->next;
            }
            cur = cur->next;
        }
        odd_tail->next = even->next;
        even_tail->next = nullptr;
        return odd->next;
    }
};
