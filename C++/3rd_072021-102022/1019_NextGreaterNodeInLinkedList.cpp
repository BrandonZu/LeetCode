//
// Created by BrandonZu on 10/29/21.
//

#include "common.h"
#include "ListNode.h"

// Runtime 72ms(>94%) | Memory Usage 40MB(>81%)
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        int len = 0;
        for(ListNode* tmp = head; tmp; tmp = tmp->next) {
            len++;
        }
        vector<int> res(len, 0);
        stack<pair<int, int>> stk;
        int i = 0;
        for(ListNode* tmp = head; tmp; tmp = tmp->next) {
            while(!stk.empty() && tmp->val > stk.top().second) {
                res[stk.top().first] = tmp->val;
                stk.pop();
            }
            stk.push({i, tmp->val});
            ++i;
        }
        return res;
    }
};

