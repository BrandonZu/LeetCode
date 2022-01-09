//
// Created by BrandonZu on 1/9/22.
//

#include "common.h"

// Runtime 149ms(>67%) | Memory Usage 9.6MB(>72%)
class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int n = s.size();
        unordered_map<char, int> char_cnt;
        int diff = 0;
        int l = 0, r = 0;
        int max_len = 0;
        while(r < n) {
            if(char_cnt[s[r]] == 0)
                diff++;
            char_cnt[s[r]]++;
            while(diff > 2) {
                char_cnt[s[l]]--;
                if(char_cnt[s[l]] == 0)
                    diff--;
                l++;
            }
            max_len = max(max_len, r - l + 1);
            r++;
        }
        return max_len;
    }
};
