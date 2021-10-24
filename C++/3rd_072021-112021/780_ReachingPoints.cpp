//
// Created by BrandonZu on 10/20/21.
//

#include "common.h"

// Runtime 0ms(>100%) | Memory Usage 5.9MB(>17%)
class Solution {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        while(tx >= sx && ty >= sy) {
            if(tx == ty)
                break;
            if(tx > ty) {
                if(ty > sy)
                    tx %= ty;
                else
                    return tx % sy == sx % sy;
            }
            else {
                if(tx > sx)
                    ty %= tx;
                else
                    return ty % sx == sy % sx;
            }
        }
        return tx == sx && ty == sy;
    }
};
