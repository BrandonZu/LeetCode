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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        int i = 1;
        ListNode* pre_head = dummy, * tail;
        for(int i = 0; i < left - 1; i++)
            pre_head = pre_head->next;
        tail = pre_head->next;
        for(int i = 0; i < right - left; i++) {
            ListNode* cur = tail->next, * cur_next = cur->next;
            cur->next = pre_head->next;
            pre_head->next = cur;
            tail->next = cur_next;
        }
        return dummy->next;
    }
};

