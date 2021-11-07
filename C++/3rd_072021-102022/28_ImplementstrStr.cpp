//
// Created by BrandonZu on 10/12/21.
//

#include "common.h"

class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.empty()) return 0;
        for(int i = 0; i + needle.size() - 1 < haystack.size(); i++) {
            bool flag = true;
            for(int j = 0; j < needle.size(); j++) {
                if(haystack[i + j] != needle[j]) {
                    flag = false;
                    break;
                }
            }
            if(flag) return i;
        }
        return -1;
    }
};
