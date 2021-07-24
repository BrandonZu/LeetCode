//
// Created by BrandonZu on 2021/7/24.
//

#include "common.h"

// Runtime 0ms(>100%) | Memory Usage 7.4MB(>60%)
class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        s.push_back(' ');

        // Reverse Each Word
        auto start = s.find_first_not_of(' ');
        while(start != string::npos) {
            auto end = s.find_first_of(' ', start);
            int l = start, r = end - 1;
            while(l < r)
                swap(s[l++], s[r--]);
            start = s.find_first_not_of(' ', end);
        }

        // Remove Spaces
        int pos = 0;
        auto i = s.find_first_not_of(' ');
        while(i != string::npos) {
            while(s[i] != ' ')
                s[pos++] = s[i++];
            s[pos++] = ' ';
            i = s.find_first_not_of(' ', i);
        }
        return s.substr(0, pos - 1);
    }
};
