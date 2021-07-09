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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(-999);
        dummy->next = head;
        ListNode* pre = dummy, * cur = dummy->next;
        while(cur) {
            ListNode* next = cur->next;
            if(next && next->val == cur->val) {
                while(next && next->val == cur->val)
                    next = next->next;
                pre->next = next;
                cur = next;
            }
            else {
                pre = cur;
                cur = cur->next;
            }
        }
        return dummy->next;
    }
};
