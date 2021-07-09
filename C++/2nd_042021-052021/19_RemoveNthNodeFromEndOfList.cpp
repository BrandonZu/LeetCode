using namespace std;

struct ListNode {
    ListNode* next;
    int val;
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* pre = dummy, * cur = head, *next = head;
        for(int i = 0; i < n; i++) {
            next = next->next;
        }
        while(next) {
            next = next->next;
            pre = cur;
            cur = cur->next;
        }
        pre->next = cur->next;
        return dummy->next;
    }
};
