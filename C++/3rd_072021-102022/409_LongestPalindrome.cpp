//
// Created by BrandonZu on 11/2/21.
//

#include "common.h"

// Runtime 0ms() | Memory Usage MB()
class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> letter_cnt;
        for(char c: s) {
            letter_cnt[c]++;
        }
        int odd_cnt= 0;
        for(auto p: letter_cnt) {
            if(p.second & 1)
                odd_cnt++;
        }
        return s.size() - odd_cnt + (odd_cnt != 0 ? 1 : 0);
    }
};
