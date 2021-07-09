#include <vector>
#include <queue>
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

// Divide and Conquer
class Solution_1 {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty())
            return nullptr;
        return merge(lists, 0, (int)lists.size() - 1);
    }

    ListNode* merge(vector<ListNode*>& lists, int left, int right) {
        if(left >= right)
            return lists[left];
        int mid = left + (right - left) / 2;
        ListNode* l1 = merge(lists, left, mid);
        ListNode* l2 = merge(lists, mid + 1, right);
        return mergeTwoLists(l1, l2);
    }

    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(-1);
        ListNode* tail = dummy;
        while(l1 && l2) {
            if(l1->val < l2->val) {
                tail->next = l1;
                tail = l1;
                l1 = l1->next;
            }
            else {
                tail->next = l2;
                tail = l2;
                l2 = l2->next;
            }
        }
        if(l1) {
            tail->next = l1;
        }
        if(l2) {
            tail->next = l2;
        }
        return dummy->next;
    }
};

// Priority Queue
struct myComp {
    bool operator()(const ListNode *a, const ListNode *b) const {
        return a->val > b->val;
    }
};

class Solution_2 {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* result = new ListNode(-1);
        ListNode* tail = result;
        priority_queue<ListNode*, vector<ListNode*>, myComp> pq;
        for(ListNode* p : lists) {
            if(p)
                pq.push(p);
        }
        while(!pq.empty()) {
            ListNode* node = pq.top();
            pq.pop();
            tail->next = node;
            tail = node;
            if(node->next) {
                pq.push(node->next);
            }
        }
        return result->next;
    }
};

int main() {

    ListNode* head1 = new ListNode(1);
    head1->next = new ListNode(2);
    ListNode* head2 = new ListNode(1);
    head2->next = new ListNode(3);
    ListNode* head3 = new ListNode(2);
    head3->next = new ListNode(6);
    vector<ListNode*> list = {head1, head2, head3};
    Solution_1 ss;
    ss.mergeKLists(list);
    return 0;
}

