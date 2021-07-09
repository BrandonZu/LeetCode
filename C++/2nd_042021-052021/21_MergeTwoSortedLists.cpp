#include <iostream>
using namespace std;

class ListNode {
public:
    ListNode* next;
    int val;
    ListNode(int val = 0) {
        this->val = val;
        this->next = nullptr;
    }
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(-1);
        ListNode* tail = dummy;
        while(l1 && l2) {
            if(l1->val < l2->val) {
                tail->next = l1;
                tail = l1;
                l1 = l1->next;
            }
            else {
                tail->next = l2;
                tail = l2;
                l2 = l2->next;
            }
        }
        if(l1) {
            tail->next = l1;
        }
        if(l2) {
            tail->next = l2;
        }
        return dummy->next;
    }
};
