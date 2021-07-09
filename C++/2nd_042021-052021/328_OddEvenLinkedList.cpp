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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* odd = new ListNode(-1), * odd_tail = odd;
        ListNode* even = new ListNode(-1), * even_tail = even;
        ListNode* cur = head;
        while(cur) {
            odd_tail->next = cur;
            odd_tail = cur;
            cur = cur->next;
            if(cur) {
                even_tail->next = cur;
                even_tail = cur;
                cur = cur->next;
            }
        }
        odd_tail->next = even->next;
        even_tail->next = nullptr;
        return odd->next;
    }
};

