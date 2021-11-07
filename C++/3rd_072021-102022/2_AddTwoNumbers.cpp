//
// Created by BrandonZu on 2021/8/4.
//

#include "common.h"
#include "ListNode.h"

// Runtime 28ms(>71%) | Memory Usage 70.8MB(>98%)
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int len_1 = 0, len_2 = 0;
        ListNode* tmp = l1;
        while(tmp) len_1++, tmp = tmp->next;
        tmp = l2;
        while(tmp) len_2++, tmp = tmp->next;
        ListNode* l = len_1 > len_2 ? l1 : l2;
        ListNode* s = len_1 > len_2 ? l2 : l1;
        ListNode* res = l;

        int mv = 0;
        ListNode* pre = l;
        while(l && s) {
            l->val = l->val + s->val + mv;
            if(l->val >= 10)
                l->val -= 10, mv = 1;
            else
                mv = 0;
            pre = l;
            l = l->next, s = s->next;
        }

        while(l && mv) {
            l->val += mv;
            if(l->val >= 10)
                l->val -= 10, mv = 1;
            else
                mv = 0;
            pre = l;
            l = l->next;
        }

        if(mv)
            pre->next = new ListNode(mv);
        return res;
    }
};

