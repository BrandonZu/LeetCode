//
// Created by BrandonZu on 11/16/21.
//

#include "common.h"

// Runtime 0ms(>100%) | Memory Usage 6.1MB(>99%)
class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int read(char *buf, int n) {
        int offset = 0;
        while(offset < n) {
            int cur = read4(buf + offset);
            offset += cur;
            if(cur < 4) {
                break;
            }
        }
        return min(n, offset);
    }
};

