//
// Created by BrandonZu on 12/6/21.
//

#include "common.h"

// Runtime 0ms(>100%) | Memory Usage 6.1MB(>98%)
class Solution {
public:
    string reorganizeString(string s) {
        int n = s.size();
        vector<int> cnt(26);
        int most_freq = 0;
        for(char c: s) {
            cnt[c - 'a']++;
        }
        for(int i = 1; i < 26; i++) {
            if(cnt[i] > cnt[most_freq])
                most_freq = i;
        }
        if(2 * cnt[most_freq] - 1 > n) {
            return "";
        }
        int i = 0;
        string res(n, ' ');
        while(cnt[most_freq]) {
            res[i] = most_freq + 'a';
            cnt[most_freq]--;
            i += 2;
        }
        for(int c = 0; c < 26; c++) {
            while(cnt[c]) {
                if(i >= s.size()) i = 1;
                res[i] = 'a' + c;
                cnt[c]--;
                i += 2;
            }
        }
        return res;
    }
};
