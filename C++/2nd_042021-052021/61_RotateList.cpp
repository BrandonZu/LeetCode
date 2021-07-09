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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head)
            return nullptr;
        int len = 1;
        ListNode* tmp = head;
        while(tmp->next) {
            tmp = tmp->next;
            len++;
        }
        tmp->next = head;

        k %= len;
        for(int i = 0; i < len - k - 1; i++)
            head = head->next;

        ListNode* res = head->next;
        head->next = nullptr;
        return res;
    }
};
