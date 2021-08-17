//
// Created by BrandonZu on 2021/8/17.
//

#include "common.h"

// Runtime 20ms(>48%) | Memory Usage 8.3MB(>72%)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> hash_win;
        int len = 0;
        for(int l = 0, r = 0; r < s.size(); r++) {
            hash_win[s[r]]++;

            while(hash_win[s[r]] > 1) {
                hash_win[s[l]]--;
                l++;
            }
            len = max(len, r - l + 1);
        }
        return len;
    }
};
