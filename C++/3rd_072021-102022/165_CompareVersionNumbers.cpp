//
// Created by BrandonZu on 2021/8/18.
//

#include "common.h"

// Runtime 0ms(>100%) | Memory Usage 6MB(>96%)
class Solution {
public:
    int compareVersion(string version1, string version2) {
        int pos_1 = 0, pos_2 = 0;
        int tmp_1, tmp_2;
        while(pos_1 < version1.size() && pos_2 < version2.size()) {
            tmp_1 = 0;
            while(pos_1 < version1.size() && version1[pos_1] != '.') {
                tmp_1 *= 10;
                tmp_1 += version1[pos_1] - '0';
                pos_1++;
            }
            tmp_2 = 0;
            while(pos_2 < version2.size() && version2[pos_2] != '.') {
                tmp_2 *= 10;
                tmp_2 += version2[pos_2] - '0';
                pos_2++;
            }
            if(tmp_1 < tmp_2)
                return -1;
            if(tmp_1 > tmp_2)
                return 1;
            pos_1++, pos_2++;
        }
        // Version1 is longer
        while(pos_1 < version1.size()) {
            tmp_1 = 0;
            while(pos_1 < version1.size() && version1[pos_1] != '.') {
                tmp_1 *= 10;
                tmp_1 += version1[pos_1] - '0';
                pos_1++;
            }
            if(tmp_1 > 0)
                return 1;
            pos_1++;
        }
        // Version2 is longer
        while(pos_2 < version2.size()) {
            tmp_2 = 0;
            while(pos_2 < version2.size() && version2[pos_2] != '.') {
                tmp_2 *= 10;
                tmp_2 += version2[pos_2] - '0';
                pos_2++;
            }
            if(tmp_2 > 0)
                return -1;
            pos_2++;
        }
        return 0;
    }
};

