//
// Created by BrandonZu on 3/4/22.
//

#include "common.h"

// Runtime 7ms(>60%) | Memory Usage 8.9MB(>53%)
class Solution {
public:
    int compress(vector<char>& chars) {
        if(chars.size() <= 1) return chars.size();
        int slow = 0;
        for(int i = 0; i < chars.size(); i++) {
            int j = i + 1;
            while(j < chars.size() && chars[j] == chars[j - 1]) {
                j++;
            }
            int len = j - i;
            chars[slow++] = chars[i];
            if(len == 1) continue;
            for(char c: to_string(len)) {
                chars[slow++] = c;
            }
            i = j - 1;
        }
        return slow;
    }
};
