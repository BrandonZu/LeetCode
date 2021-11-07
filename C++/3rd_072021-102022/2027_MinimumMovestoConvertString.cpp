//
// Created by BrandonZu on 10/3/21.
//

#include "common.h"

class Solution {
public:
    int minimumMoves(string s) {
        int cnt = 0;
        int pos = 0;
        while(pos < s.size()) {
            if(s[pos] == 'X') {
                pos += 3;
                cnt++;
            }
            else {
                pos++;
            }
        }
        return cnt;
    }
};
