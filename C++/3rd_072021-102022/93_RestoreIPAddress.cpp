//
// Created by BrandonZu on 2021/7/30.
//

#include "common.h"

// Runtime 0ms(>100%) | Memory Usage(>50%)
class Solution {
    vector<string> result;
public:
    bool checkValid(const string& str) {
        if(str.size() > 3 || str.empty()) return false;
        if(str[0] == '0' && str.size() != 1)
            return false;
        int tmp = 0;
        for(int i = 0; i < str.size(); i++) {
            if(str[i] >= '0' && str[i] <= '9')
                tmp *= 10, tmp += str[i] - '0';
            else
                return false;
        }
        return tmp <= 255;
    }

    void backtrack (string& s, int pos, int cnt) {
        if(cnt == 3) {
            if(checkValid(s.substr(pos)))
                result.push_back(s);
            return;
        }

        for(int i = pos; i <= pos + 2 && i <= s.size() - 1; i++) {
            if(checkValid(s.substr(pos, i - pos + 1))) {
                s.insert(i + 1, ".");
                backtrack(s, i + 2, cnt + 1);
                s.erase(i + 1,1);
            }
        }
    }

    vector<string> restoreIpAddresses(string s) {
        backtrack(s, 0, 0);
        return result;
    }
};