//
// Created by BrandonZu on 1/11/22.
//

#include "common.h"

// Runtime 4ms(>58%) | Memory Usage 6.6MB(>32%)
class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        if(abs((int)s.size() - (int)t.size()) > 1)
            return false;
        if(s.size() > t.size())
            return isOneEditDistance(t, s);
        bool used = false;
        int i = 0, j = 0;
        while(i < s.size()) {
            if(s[i] != t[j]) {
                if(used) return false;
                used = true;
                if(s.size() != t.size())
                    j++;
                else
                    i++, j++;
            }
            else {
                i++, j++;
            }
        }
        return used || t.size() == s.size() + 1;
    }
};
