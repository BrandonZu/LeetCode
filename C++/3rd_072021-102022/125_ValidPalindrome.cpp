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

// 1st Review
// Runtime 4ms(>92%) | Memory Usage 7.3MB(>71%)
class Solution_R1 {
public:
    bool isPalindrome(string s) {
        int n = s.size();
        int l = 0, r = n - 1;
        while(l < r) {
            while(l < r && !isalnum(s[l])) {
                l++;
            }
            while(l < r && !isalnum(s[r])) {
                r--;
            }
            if(l < r && tolower(s[l]) != tolower(s[r]))
                return false;
            l++, r--;
        }
        return true;
    }
};
