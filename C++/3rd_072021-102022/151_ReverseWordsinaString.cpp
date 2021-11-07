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

// 1st Review 09/28/21
// Runtime 0ms(>100%) | Memory Usgae 7.2MB(>76%)
class Solution_R1 {
public:
    string reverseWords(string s) {
        // Remove extra spaces
        int i = 0;
        int j = s.find_first_not_of(' ');
        s.push_back(' ');
        while(j != string::npos) {
            while(s[j] != ' ') {
                s[i++] = s[j++];
            }
            s[i++] = ' ';
            j = s.find_first_not_of(' ', j);
        }
        i--;
        reverse(s.begin(), s.begin() + i);
        int pos = 0;
        while(pos < s.size()) {
            int next = s.find_first_of(' ', pos);
            reverse(s.begin() + pos, s.begin() + next);
            pos = next + 1;
        }
        reverse(s.begin() + pos, s.end());
        return s.substr(0, i);
    }
};