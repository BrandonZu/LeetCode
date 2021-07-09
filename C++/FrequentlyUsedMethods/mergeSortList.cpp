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
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next)
            return head;

        ListNode* mid = middleNode(head);
        ListNode* rightHead = mid->next;
        mid->next = nullptr;

        ListNode* left = sortList(head);
        ListNode* right = sortList(rightHead);

        return mergeTwoLists(left, right);
    }

    ListNode* middleNode(ListNode* head) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* slow = dummy, * fast = dummy;
        while(fast) {
            fast = fast->next;
            if(fast) {
                fast = fast->next;
                slow = slow->next;
            }
        }
        delete dummy;
        return slow;
    }

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
        ListNode* tmp = dummy->next;
        delete dummy;
        return tmp;
    }
};
