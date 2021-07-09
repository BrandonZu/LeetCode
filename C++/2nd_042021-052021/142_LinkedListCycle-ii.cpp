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
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head, * fast = head;
        while(fast) {
            fast = fast->next;
            if(!fast)
                break;
            fast = fast->next;
            slow = slow->next;
            if(slow == fast) {
                fast = head;
                while(slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
        }
        return nullptr;
    }
};

