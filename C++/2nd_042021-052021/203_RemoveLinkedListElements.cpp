using namespace std;

class ListNode {
public:
    ListNode* next;
    int val;
    ListNode(int val): val(val), next(nullptr) {}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* pre = dummy, * cur = head;
        while(cur) {
            if(cur->val == val) {
                pre->next = cur->next;
                cur = cur->next;
            }
            else {
                pre = cur;
                cur = cur->next;
            }
        }
        return dummy->next;
    }
};

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    Solution ss;
    ss.removeElements(head, 2);
}
