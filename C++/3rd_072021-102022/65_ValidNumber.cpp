//
// Created by BrandonZu on 11/14/21.
//

#include "common.h"

// Runtime 0ms(>100%) | Memory Usage 5.8MB(>93%)
class Solution {
public:
    bool isInteger(string& s, int l, int r) {
        if(l > r) return false;
        if(s[l] == '-' || s[l] == '+')
            l++;
        int cnt = 0;
        while(l <= r && isdigit(s[l]))
            l++, cnt++;
        return l > r && cnt != 0;
    }

    bool isDecimal(string& s, int l, int r) {
        if(l > r) return false;
        if(s[l] == '-' || s[l] == '+')
            l++;
        int cnt = 0;
        while(l <= r && isdigit(s[l]))
            l++, cnt++;
        if(l > r || s[l] != '.') return false;
        l++;
        if(cnt == 0) {
            while(l <= r && isdigit(s[l]))
                l++, cnt++;
            return l > r && cnt != 0;
        }
        else {
            while(l <= r && isdigit(s[l]))
                l++;
            return l > r;
        }
    }

    bool isNumber(string s) {
        int n = s.size();
        if(s.find('e') == string::npos && s.find('E') == string::npos) {
            return isInteger(s, 0, n - 1) || isDecimal(s, 0, n - 1);
        }
        else {
            int pos;
            if(s.find('e') != string::npos)
                pos = s.find('e');
            else
                pos = s.find('E');
            return (isInteger(s, 0, pos - 1) || isDecimal(s, 0, pos - 1)) && isInteger(s, pos + 1, n - 1);
        }
    }
};
