#include<iostream>

using namespace std;

class ListNode {
public:
    ListNode* next;
    int val;

    ListNode(int val = 0) {
        this->val = val;
        next = nullptr;
    }
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(-1);
        ListNode* tail = head;
        bool carry = false;
        while(l1 || l2) {
            int cur = 0;
            if(l1) {
                cur += l1->val;
                l1 = l1->next;
            }
            if(l2) {
                cur += l2->val;
                l2 = l2->next;
            }
            cur = carry ? cur + 1 : cur;
            carry = cur >= 10 ? true : false;
            tail->next = new ListNode(cur % 10);
            tail = tail->next;
        }
        if(carry)
            tail->next = new ListNode(1);
        return head->next;
    }
};