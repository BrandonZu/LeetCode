//
// Created by BrandonZu on 11/10/21.
//

#include "common.h"

// Runtime 0ms(>100%) | Memory Usage 6MB(>100%)
class Solution {
public:
    bool canPermutePalindrome(string s) {
        int char_cnt[26] = {};
        for(char c: s) {
            char_cnt[c - 'a']++;
        }
        int odd = -1;
        for(int i = 0; i < 26; i++) {
            if(char_cnt[i] % 2 == 1) {
                if(odd != -1)
                    return false;
                odd = i;
            }
        }
        return true;
    }
};

