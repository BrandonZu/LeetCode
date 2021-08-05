//
// Created by BrandonZu on 2021/8/4.
//

#include "common.h"

// Runtime 0ms(>100%) | Memory Usage 7MB(>88%)
class Solution {
public:
    int myAtoi(string s) {
        int pos = 0;
        long result = 0, flag = 1;
        // Ignore whitespaces
        while(pos < s.size() && s[pos] == ' ') pos++;

        if(pos < s.size() && (s[pos] == '-' || s[pos] == '+')) {
            flag = s[pos] == '+' ? 1 : -1;
            pos++;
        }

        for(int i = pos; i < s.size(); i++) {
            if(s[i] >= '0' && s[i] <= '9') {
                result *= 10;
                result += s[i] - '0';
                if(flag * result > INT_MAX) return INT_MAX;
                if(flag * result < INT_MIN) return INT_MIN;
            }
            else
                return result * flag;
        }

        return result * flag;
    }
};
