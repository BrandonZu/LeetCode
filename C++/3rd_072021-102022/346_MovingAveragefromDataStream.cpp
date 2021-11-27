//
// Created by BrandonZu on 11/27/21.
//

#include "common.h"

// Runtime 30ms(>29%) | Memory Usage 14MB(>55%)
class MovingAverage {
    queue<int> q;
    int sz;
    int cnt;
public:
    MovingAverage(int size) {
        sz = size;
        cnt = 0;
    }

    double next(int val) {
        if(q.size() == sz) {
            cnt -= q.front();
            q.pop();
        }
        q.push(val);
        cnt += val;
        return cnt / (double)q.size();
    }
};
