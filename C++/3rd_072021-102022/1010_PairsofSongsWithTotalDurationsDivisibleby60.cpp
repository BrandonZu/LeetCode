//
// Created by BrandonZu on 10/24/21.
//

#include "common.h"

// Runtime 30ms(>68%) | Memory Usage 23MB(>90%)
class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        vector<int> count(60, 0);
        for(int i = 0; i < time.size(); i++) {
            count[time[i] % 60]++;
        }
        int cnt = 0;
        cnt += count[0] * (count[0] - 1) / 2;
        cnt += count[30] * (count[30] - 1) / 2;
        for(int i = 1; i < 30; i++) {
            int j = 60 - i;
            cnt += count[i] * count[j];
        }
        return cnt;
    }
};

// Runtime 28ms(>80%) | Memory Usage 23MB(>90%)
class Solution2 {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        vector<int> count(60, 0);
        int res = 0;
        for(int t: time) {
            res += count[(60 - t % 60) % 60];
            ++count[t % 60];
        }
        return res;
    }
};
