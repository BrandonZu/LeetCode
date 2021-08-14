//
// Created by BrandonZu on 2021/8/14.
//

#include "common.h"

// Runtime 7ms(>34%) | Memory Usage 9.9MB(>49%)
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int cur = 0, start = 0;
        for(int i = 0; i < gas.size(); i++)
            cur = cur + gas[i] - cost[i];
        if(cur < 0) return -1;

        cur = 0, start = 0;
        for(int i = 0; i < gas.size(); i++) {
            cur = cur + gas[i] - cost[i];
            if(cur < 0)
                start = i + 1, cur = 0;
        }
        if(start > gas.size() - 1)
            return -1;
        else
            return start;
    }
};
