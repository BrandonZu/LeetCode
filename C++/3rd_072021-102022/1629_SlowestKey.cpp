//
// Created by BrandonZu on 10/23/21.
//

#include "common.h"

// Runtime 12ms(>32%) | Memory Usage 11MB(>20%)
class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        char res;
        int cur_max = 0;
        int pre = 0;
        for(int i = 0; i < releaseTimes.size(); i++) {
            int dur = releaseTimes[i] - pre;
            if(dur > cur_max) {
                cur_max = dur;
                res = keysPressed[i];
            }
            else if(dur == cur_max) {
                res = max(res, keysPressed[i]);
            }
            pre = releaseTimes[i];
        }
        return res;
    }
};

