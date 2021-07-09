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
    void reorderList(ListNode* head) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* fast = dummy, * slow = dummy;
        while(fast) {
            fast = fast->next;
            if(fast)
                fast = fast->next;
            slow = slow->next;
        }
        ListNode* head2 = slow->next;
        slow->next = nullptr;
        head2 = reverseList(head2);
        ListNode* tail = head;
        while(head2) {
            ListNode* tmp1 = tail->next;
            tail->next = head2;
            ListNode* tmp2 = head2->next;
            head2->next = tmp1;
            head2 = tmp2;
            tail = tmp1;
        }
    }

    ListNode* reverseList(ListNode* head) {
        ListNode* pre = nullptr;
        ListNode* cur = head;
        while(cur) {
            ListNode* tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }
        return pre;
    }
};

