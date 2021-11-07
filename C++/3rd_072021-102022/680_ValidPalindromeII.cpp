//
// Created by BrandonZu on 9/19/21.
//

#include "common.h"

// Runtime 81ms(>14%) | Memory Usage 20MB(>69%)
class Solution {
public:
    bool validPalindrome(string s) {
        int l = 0, r = s.size() - 1;
        bool used = false;
        while(l < r) {
            if(s[l] == s[r])
                l++, r--;
            else {
                if(used)
                    return false;
                else
                    return judge(l + 1, r, s) || judge(l, r - 1, s);
            }
        }
        return true;
    }

    bool judge(int l, int r, const string& s) {
        while(l < r) {
            if(s[l] != s[r])
                return false;
            l++, r--;
        }
        return true;
    }
};
