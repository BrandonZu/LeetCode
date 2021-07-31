//
// Created by BrandonZu on 2021/7/30.
//

#include "common.h"

class Solution {
    vector<string> result;
public:
    void dfs(const string& s, int pos, int cnt) {
        if(cnt == 4) {
            result.push_back(path);
            return;
        }
        if(pos >= s.size()) return;

        int tmp = 0;
        for(int i = pos; i <= pos + 2 && tmp <= 255; i++) {
            if(s[i] == '0' && tmp == 0) {
                path += "0.";
                dfs(s, i + 1,cnt + 1);
                path.pop_back();
            }

            if(s[pos] >= '0' && s[pos] <= '9') {
                tmp
            }
        }
    }

    vector<string> restoreIpAddresses(string s) {
        dfs(s, 0, 0);
        return result;
    }
};
