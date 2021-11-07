//
// Created by BrandonZu on 2021/8/23.
//

#include "common.h"

// Runtime 8ms(>52%) | Memory Usage 7.5MB(>44%)
class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0, r = s.size() - 1;
        while(l < r) {
            // Find first alphanumeric character
            while(l < r && !isalnum(s[l]))
                l++;
            while(l < r && !isalnum(s[r]))
                r--;
            if(tolower(s[l]) != tolower(s[r]))
                return false;
            l++, r--;
        }
        return true;
    }
};
