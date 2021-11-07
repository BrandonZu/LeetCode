//
// Created by BrandonZu on 2021/7/23.
//

#include "common.h"

// Runtime 4ms(>100%) | Memory Usage 7.4MB(>42%)
class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> s_map(27, 0);
        vector<int> t_map(27, 0);
        for(char c : s)
            s_map[c - 'a']++;
        for(char c : t)
            t_map[c - 'a']++;
        for(int i = 0; i < 27; i++)
            if(s_map[i] != t_map[i])
                return false;
        return true;
    }
};