//
// Created by BrandonZu on 2/19/22.
//

#include "common.h"

// Runtime 197ms(>62%) | Memory Usage 9.6MB(>72%)
bool knows(int a, int b);
class Solution {
public:
    int findCelebrity(int n) {
        int cur = 0, next = 1;
        while(next < n) {
            bool ret = knows(cur, next);
            if(ret) {
                cur = next;
            }
            next++;
        }
        for(int i = 0; i < n; i++) {
            if(i != cur) {
                if(knows(cur, i) || !knows(i, cur)) {
                    return -1;
                }
            }
        }
        return cur;
    }
};