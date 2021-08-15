//
// Created by BrandonZu on 2021/8/15.
//

#include "common.h"

// Runtime 4ms(>73%) | Memory Usage 9.4MB(>29%)
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) return "";
        string res;
        int min_size = strs[0].size(), min_pos = 0;
        for(int i = 0; i < strs.size(); i++) {
            if(strs[i].size() < min_size) {
                min_size = strs[i].size();
                min_pos = i;
            }
        }
        res = strs[min_pos];

        for(string s: strs) {
            for(int j = 0; j < res.size(); j++) {
                if(s[j] != res[j]) {
                    res = move(res.substr(0, j));
                    break;
                }
            }
            if(res.empty())
                return res;
        }
        return res;
    }
};

