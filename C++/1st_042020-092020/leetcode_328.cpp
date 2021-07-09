#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *oddEvenList(ListNode *head) {
        if(!head)
            return NULL;
        ListNode* even = head->next;
        ListNode* odd = head;
        ListNode* even_head = even;
        while(even && even->next) {
            odd->next = even->next;
            odd = even->next;
            even->next = odd->next;
            even = odd->next;
        }
        odd->next = even_head;
        return head;
    }
};