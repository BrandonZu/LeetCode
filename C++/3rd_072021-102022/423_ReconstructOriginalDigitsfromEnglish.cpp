//
// Created by BrandonZu on 12/26/21.
//

#include "common.h"

// Runtime 12ms(>95%) | Memory Usage 8.8MB(>87%)
class Solution {
public:
    string originalDigits(string s) {
        vector<int> char_cnt(26, 0);
        for(char c: s) {
            char_cnt[c - 'a']++;
        }

        vector<int> num_cnt(10, 0);
        num_cnt[6] = char_cnt['x' - 'a'];
        num_cnt[4] = char_cnt['u' - 'a'];
        num_cnt[5] = char_cnt['f' - 'a'] - num_cnt[4];
        num_cnt[2] = char_cnt['w' - 'a'];
        num_cnt[0] = char_cnt['z' - 'a'];
        num_cnt[8] = char_cnt['g' - 'a'];
        num_cnt[1] = char_cnt['o' - 'a'] - num_cnt[0] - num_cnt[2] - num_cnt[4];
        num_cnt[3] = char_cnt['r' - 'a'] - num_cnt[0] - num_cnt[4];
        num_cnt[7] = char_cnt['s' - 'a'] - num_cnt[6];
        num_cnt[9] = char_cnt['i' - 'a'] - num_cnt[5] - num_cnt[6] - num_cnt[8];

        string res;
        for(int i = 0; i < 10; i++) {
            for(int j = 0; j < num_cnt[i]; j++) {
                res += '0' + i;
            }
        }
        return res;
    }
};
