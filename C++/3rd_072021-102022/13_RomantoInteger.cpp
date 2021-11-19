//
// Created by BrandonZu on 2021/8/15.
//

#include "common.h"

// Runtime 12ms(>57%) | Memory Usage 8.3MB(>14%)
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

// 1st Review 11/18/21
// Runtime 24ms(>17%) | Memory Usage 7.9MB(>44%)
class Solution_R1 {
public:
    int romanToInt(string s) {
        unordered_map<char, int> romanToIntMap = {
                {'M', 1000}, {'D', 500}, {'C', 100}, {'L', 50}, {'X', 10}, {'V', 5}, {'I', 1}
        };
        int integer = 0;
        for(int i = 0; i < s.size(); i++) {
            if(i + 1 < s.size() && romanToIntMap[s[i + 1]] > romanToIntMap[s[i]])
                integer -= romanToIntMap[s[i]];
            else
                integer += romanToIntMap[s[i]];
        }
        return integer;
    }
};
