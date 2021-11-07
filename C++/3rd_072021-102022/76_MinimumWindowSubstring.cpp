//
// Created by BrandonZu on 2021/8/16.
//

#include "common.h"

// Runtime 20ms(>56%) | Memory Usage 7.8MB(>50%)
class Solution {
public:
    string minWindow(string s, string t) {
        if(t.empty()) return "";
        unordered_map<char, int> hash_win, hash_target;
        for(char c: t) hash_target[c]++;

        int minPos = 0, minLen = s.size() + 10;
        int validCnt = 0;
        for(int l = 0, r = 0; r < s.size(); r++) {
            hash_win[s[r]]++;
            if(hash_win[s[r]] <= hash_target[s[r]]) {
                validCnt++;
            }

            while(hash_win[s[l]] > hash_target[s[l]]) {
                hash_win[s[l]]--;
                l++;
            }

            if(validCnt == t.size() && r - l + 1 < minLen) {
                minLen = r - l + 1;
                minPos = l;
            }
        }
        return minLen == s.size() + 10 ? "" : s.substr(minPos, minLen);
    }
};