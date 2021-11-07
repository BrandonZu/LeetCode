//
// Created by BrandonZu on 2021/8/15.
//

#include "common.h"

// Runtime 12ms(<57%) | Memory Usage 8.3MB(>14%)
class Solution {
public:
    unordered_map<char, int> romanToIntMap;
    Solution() {
        romanToIntMap['I'] = 1;
        romanToIntMap['V'] = 5;
        romanToIntMap['X'] = 10;
        romanToIntMap['L'] = 50;
        romanToIntMap['C'] = 100;
        romanToIntMap['D'] = 500;
        romanToIntMap['M'] = 1000;
    }

    int romanToInt(string s) {
        int pos = 0;
        int res = 0;
        for(int i = 0; i < s.size(); i++) {
            if(i + 1 < s.size() && romanToIntMap[s[i + 1]] > romanToIntMap[s[i]])
                res -= romanToIntMap[s[i]];
            else
                res += romanToIntMap[s[i]];
        }
        return res;
    }
};
