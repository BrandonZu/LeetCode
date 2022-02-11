//
// Created by BrandonZu on 2/11/22.
//

#include "common.h"

// Runtime 19ms(>83%) | Memory Usage 16.1MB(>96%)
class Solution {
public:
    void reverse(vector<char>& s, int l, int r) {
        while(l < r) {
            swap(s[l], s[r]);
            l++, r--;
        }
    }
    void reverseWords(vector<char>& s) {
        int n = s.size();
        int l = 0, r = n - 1;
        reverse(s, 0, n - 1);
        int prev = 0;
        for(int i = 1; i < n; i++) {
            if(s[i] == ' ') {
                reverse(s, prev, i - 1);
                prev = i + 1;
            }
        }
        reverse(s, prev, n - 1);
    }
};
