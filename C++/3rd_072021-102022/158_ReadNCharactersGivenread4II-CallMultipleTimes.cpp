//
// Created by BrandonZu on 11/20/21.
//

#include "common.h"
/**
 * The read4 API is defined in the parent class Reader4.
 *     int read4(char *buf4);
 */

// Observation 1: There might be some characters left which are read from the file
// Store these characters in the buffer - char buf4096[4096]



// Runtime 0ms(>100%) | Memory Usage 6.4MB(>17%)
class Solution {
    char buf4[4];
    int readPos = 0, charCnt = 0;
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int read(char *buf, int n) {
        for(int i = 0; i < n; ++i) {
            if(readPos == charCnt) { // Consume all the characters in the buffer
                charCnt = read4(buf4); // Read from the file again and store the characters in the buffer
                readPos = 0;
                if(charCnt == 0) {
                    return i;
                }
            }
            buf[i] = buf4[readPos++];
        }
        return n;
    }
};

// Runtime 0ms(>100%) | Memory Usage 6.1MB(>87%)
class Solution_R1 {
    int l = 0, r = 0;
    char circle_buf[4];
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int read(char *buf, int n) {
        int cnt = 0;
        if(r - l >= n) {
            for(int i = 0; i < n; i++) {
                buf[i] = circle_buf[l + i];
            }
            l += n;
            return n;
        }
        int left = r - l;
        for(int i = 0; i < left; i++) {
            buf[i] = circle_buf[l + i];
        }
        l = r = 0;
        cnt = left;

        while(cnt < n) {
            if(cnt + 4 <= n) {
                int cur = read4(buf + cnt);
                cnt += cur;
                if(cur < 4) {
                    return cnt;
                }
            }
            else {
                r = read4(circle_buf);
                int need = n - cnt;
                for(int i = 0; i < min(r, need); i++) {
                    buf[cnt + i] = circle_buf[i];
                }
                l = min(r, need);
                cnt += r;
                break;
            }
        }
        return min(cnt, n);
    }
};
