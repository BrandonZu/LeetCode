//
// Created by BrandonZu on 10/3/21.
//

#include "common.h"

// Runtime 120ms(>100%) | Memory Usage 28MB(>100%)
class Solution {
public:
    string smallestSubsequence(string s, int k, char letter, int repetition) {
        int remain = 0;
        for(char c: s)
            if(c == letter)
                remain++;
        string stk;
        for(int i = 0; i < s.size(); i++) {
            char c = s[i];
            // Try to pop characters in the back
            while(!stk.empty() && stk.back() > c && (s.size() - i + stk.size() - 1 >= k) && (stk.back() != letter || remain > repetition)) {
                if(stk.back() == letter) {
                    repetition++;
                }
                stk.pop_back();
            }

            if(stk.size() < k) {
                if(c == letter) {
                    repetition--;
                    stk.push_back(c);
                }
                else if(k - (int)stk.size() > repetition) { // Why is it necessary to add (int) here?
                    stk.push_back(c);
                }
            }
            if(c == letter)
                remain--;
        }

        return stk;
    }
};
