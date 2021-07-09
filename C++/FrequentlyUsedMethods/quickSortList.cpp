using namespace std;

struct ListNode {
    ListNode* next;
    int val;
    ListNode(int val = 0) {
        this->next = nullptr;
        this->val = val;
    }
};

class Solution {
public:
    ListNode* get_tail(ListNode* head) {
        if(!head) {
            return head;
        }
        while(head->next) {
            head = head->next;
        }
        return head;
    }

    ListNode* quickSortList(ListNode* head) {
        if(!head || !head->next) {
            return head;
        }
        auto left = new ListNode(-1), mid = new ListNode(-1), right = new ListNode(-1);
        auto l_tail = left, m_tail = mid, r_tail = right;

        int pivot = head->val;
        ListNode* cur = head;
        for(auto cur = head; cur; cur = cur->next) {
            if(cur->val < pivot) {
                l_tail->next = cur;
                l_tail = cur;
            }
            else if(cur->val > pivot) {
                r_tail->next = cur;
                r_tail = cur;
            }
            else {
                m_tail->next = cur;
                m_tail = cur;
            }
        }

        l_tail->next = r_tail->next = m_tail->next = NULL;

        left->next = quickSortList(left->next);
        right->next = quickSortList(right->next);

        get_tail(left)->next = mid->next;
        get_tail(left)->next = right->next;

        ListNode* tmp = left->next;

        delete left;
        delete mid;
        delete right;

        return tmp;

    }
};