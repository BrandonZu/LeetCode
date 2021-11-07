//
// Created by BrandonZu on 11/6/21.
//

#include "common.h"

// Runtime
class Solution {
public:
    string countAndSay(int n) {
        string str = "1";
        for(int i = 2; i <= n; i++) {
            string tmp;
            int pos = 0;
            while(pos < str.size()) {
                char num = str[pos];
                int next = pos + 1;
                while(next < str.size() && str[next] == num) {
                    next++;
                }
                tmp.append(to_string(next - pos));
                tmp.push_back(num);
                pos = next;
            }
            str = tmp;
        }
        return str;
    }
};
