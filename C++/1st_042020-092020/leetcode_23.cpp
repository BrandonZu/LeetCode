#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty())
            return nullptr;
        return recurMerge(lists, 0, lists.size() - 1);
    }

    ListNode* merge(ListNode* p, ListNode* q) {
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;
        while(p && q) {
            if(p->val < q->val) {
                tail->next = p;
                tail = p;
                p = p->next;
            }
            else {
                tail->next = q;
                tail = q;
                q = q->next;
            }
        }
        if(p)
            tail->next = p;
        if(q)
            tail->next = q;
        return dummy->next;
    }

    ListNode* recurMerge(vector<ListNode*>& lists, int left, int right) {
        if(left >= right)
            return nullptr;
        int mid = left + (right - left) / 2;
        recurMerge(lists, left, mid);
        recurMerge(lists, mid+1, right);
        return merge(lists[left], lists[mid + 1]);
    }

};