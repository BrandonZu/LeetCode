#include <algorithm>
using namespace std;

class ListNode {
public:
    ListNode* next;
    int val;
};

ListNode* reverseLinkedList(ListNode* head) {
    if(!head)
        return head;
    ListNode* pre = nullptr;
    ListNode* cur = head;
    ListNode* next = cur->next;
    while(next) {
        cur->next = pre;
        pre = cur;
        cur = next;
        next = next->next;
    }
    return cur;
}



