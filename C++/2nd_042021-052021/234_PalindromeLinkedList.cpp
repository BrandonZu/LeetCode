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
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head, * pre_slow = nullptr, * fast = head;
        while(fast && fast->next) {
            fast = fast->next->next;
            ListNode* tmp = slow->next;
            slow->next = pre_slow;
            pre_slow = slow;
            slow = tmp;
        }
        if(fast)
            slow = slow->next;
        while(pre_slow && slow) {
            if(pre_slow->val != slow->val)
                return false;
            pre_slow = pre_slow->next;
            slow = slow->next;
        }
        return true;
    }
};

