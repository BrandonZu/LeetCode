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
        ListNode* dummy = new ListNode(-9999);
        dummy->next = head;
        ListNode* cur = head, * pre = dummy;
        while(cur) {
            if(cur->val != pre->val) {
                pre = cur;
                cur = cur->next;
            }
            else {
                while (cur && cur->val == pre->val) {
                    cur = cur->next;
                }
                pre->next = cur;
            }
        }
        return dummy->next;
    }
};

