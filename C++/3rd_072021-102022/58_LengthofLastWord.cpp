//
// Created by BrandonZu on 2021/8/26.
//

#include "common.h"

// Runtime 5ms(>66%) | Memory Usage 6.4MB(>99%)
class Solution {
public:
    int lengthOfLastWord(string s) {
        int start;
        int pos = s.size() - 1;
        // Find start of last word
        while(pos >= 0 && s[pos] == ' ')
            pos--;
        start = pos;
        // Find end of last word
        while(pos >= 0 && isalpha(s[pos]))
            pos--;
        return start - pos;
    }
};
