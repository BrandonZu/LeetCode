//
// Created by BrandonZu on 2021/7/31.
//

#include "common.h"

// Runtime 104ms(>75%) | Memory Usgae 75.8MB(>42%)
class Solution {
    vector<string> path;
    vector<vector<string>> result;
public:
    bool isPalindrome(const string& str) {
        int l = 0, r = str.size() - 1;
        while(l < r) {
            if(str[l++] != str[r--])
                return false;
        }
        return true;
    }

    void backtrack(const string& s, int pos) {
        if(pos >= s.size()) {
            result.push_back(path);
            return;
        }
        for(int i = pos; i <= s.size() - 1; i++) {
            if(!isPalindrome(s.substr(pos, i - pos + 1)))
                continue;
            path.push_back(s.substr(pos, i - pos + 1));
            backtrack(s, i + 1);
            path.pop_back();
        }
    }

    vector<vector<string>> partition(string s) {
        backtrack(s, 0);
        return result;
    }
};
