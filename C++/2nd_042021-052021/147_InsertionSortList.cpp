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
    ListNode* insertionSortList(ListNode* head) {
        ListNode* dummy = new ListNode(-9999);
        dummy->next = head;
        ListNode* cur = head, * pre_cur = dummy;
        while(cur) {
            ListNode* find_pre = dummy, * find = dummy->next;
            while(find != cur && find->val <= cur->val) {
                find_pre = find;
                find = find->next;
            }
            if(find != cur) {
                ListNode *cur_next = cur->next;
                cur->next = find;
                find_pre->next = cur;
                pre_cur->next = cur_next;
                cur = cur_next;
            }
            else {
                pre_cur = cur;
                cur = cur->next;
            }
        }
        return dummy->next;
    }
};

int main() {
    ListNode* head = new ListNode(5);
    head->next = new ListNode(4);
    head->next->next = new ListNode(3);
    Solution ss;
    ss.insertionSortList(head);
}
