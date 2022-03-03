//
// Created by BrandonZu on 3/3/22.
//

#include "common.h"

// Runtime 83ms(>42%) | Memory Usage 7.3MB(>99%)
int rand7();
class Solution {
public:
    int rand10() {
        int num = (rand7() - 1) * 7 * 7 + (rand7() - 1) * 7 + rand7() - 1;
        if(num >= 340) {
            return rand10();
        }
        return num % 10 + 1;
    }
};

class Solution_OP {
    stack<int> cache;
    int rand10() {
        while (cache.size() == 0) generate();
        int res = cache.top(); cache.pop();
        return res;
    }

    void generate() {
        int n = 19;
        long cur = 0, range = long(pow(7, n));
        for (int i = 0; i < n; ++i) cur += long(pow(7, i)) * (rand7() - 1);
        while (cur < range / 10 * 10) {
            cache.push(cur % 10 + 1);
            cur /= 10;
            range /= 10;
        }
    }
};
