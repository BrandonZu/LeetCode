//
// Created by BrandonZu on 2021/8/20.
//

#include "common.h"
#include "ListNode.h"

// Runtime 20ms(>86%) | Memory Usage 13.3MB(>75%)
class Solution {
public:
    class myCmp {
    public:
        bool operator() (ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, myCmp> pq;
        ListNode* dummy = new ListNode(-1);
        ListNode* tail = dummy;
        for(ListNode* p: lists) {
            if(p)
                pq.push(p);
        }
        while(!pq.empty()) {
            ListNode* cur = pq.top();
            pq.pop();
            tail->next = cur;
            tail = cur;
            if(cur->next)
                pq.push(cur->next);
        }
        return dummy->next;
    }
};
