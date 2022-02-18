//
// Created by BrandonZu on 2/18/22.
//

#include "common.h"

// Runtime 0ms(>100%) | Memory Usage 6.2MB(>22%)
class Solution {
public:
    bool isStrobogrammatic(string num) {
        unordered_map<char, char> char_map = {{'8', '8'}, {'0', '0'}, {'6', '9'}, {'9', '6'}, {'1', '1'}};
        for(int l = 0, r = num.size() - 1; l <= r; l++, r--) {
            if(char_map.find(num[l]) != char_map.end() && char_map[num[l]] == num[r])
                continue;
            else
                return false;
        }
        return true;
    }
};
