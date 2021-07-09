using namespace std;

class ListNode {
public:
    ListNode* next;
    int val;
    ListNode(int val = 0) {
        this->next = nullptr;
        this->val = val;
    }
};

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* dummy_less = new ListNode(-1);
        ListNode* dummy_more = new ListNode(-1);
        ListNode* less_tail = dummy_less, * more_tail = dummy_more;
        while(head) {
            if(head->val < x) {
                less_tail->next = head;
                less_tail = head;
            }
            else {
                more_tail->next = head;
                more_tail = head;
            }
            head = head->next;
        }
        less_tail->next = dummy_more->next;
        more_tail->next = nullptr;
        return dummy_less->next;
    }
};
