//
// Created by BrandonZu on 2/28/22.
//

#include "common.h"

// Runtime 0ms(>100%) | Memory Usage 6.4MB(>90%)
class Solution {
public:
    string decodeString(string s) {
        if(s.empty()) return "";
        int pos = 0;
        return recur(s, pos);
    }

    string recur(string& s, int& pos) {
        string res;
        while(pos < s.size() && s[pos] != ']') {
            if(isalpha(s[pos])) {
                string prefix;
                int l = pos;
                while (isalpha(s[pos])) {
                    pos++;
                }
                res += s.substr(l, pos - l);
            }
            else {
                int num = 0;
                while (pos < s.size() && isdigit(s[pos])) {
                    num *= 10;
                    num += s[pos] - '0';
                    pos++;
                }

                pos++;  // skip '['
                string mid = recur(s, pos);
                pos++;  // skip ']'

                for (int i = 0; i < num; i++) {
                    res += mid;
                }
            }
        }
        return res;
    }
};
