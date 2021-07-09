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
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;

        ListNode* cur = dummy;
        while(cur && cur->next && cur->next->next) {
            ListNode* first = cur->next;
            ListNode* second = first->next;
            cur->next = second;
            first->next = second->next;
            second->next = first;
            cur = first;
        }
        return dummy->next;
    }
};

