//
// Created by BrandonZu on 1/7/22.
//

#include "common.h"
#include "ListNode.h"

// Runtime 24ms(>79%) | Memory Usage 16.4MB(>100%)
class Solution {
    ListNode* head;
public:
    Solution(ListNode* head) {
        this->head = head;
    }

    // Reservoir Sampling
    int getRandom() {
        int res, cnt = 0;
        ListNode* cur = this->head;
        while(cur) {
            cnt++;
            if(rand() % cnt == 0) {
                res = cur->val;
            }
            cur = cur->next;
        }
        return res;
    }
};
