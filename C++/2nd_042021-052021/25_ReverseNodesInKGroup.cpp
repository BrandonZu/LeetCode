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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* pre = dummy, * end = dummy;
        while(end->next) {
            for(int i = 0; i < k && end; i++)
                end = end->next;
            // Remaining nodes < k
            if(!end) break;
            ListNode* start = pre->next;
            ListNode* next = end->next;
            end->next = nullptr;
            reverseList(start);
            start->next = next;
            pre->next = end;
            pre = end = start;
        }
        return dummy->next;
    }

    ListNode* reverseList(ListNode* head) {
        ListNode* pre = nullptr, * cur = head;
        while(cur) {
            ListNode* tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }
        return pre;
    }
};

