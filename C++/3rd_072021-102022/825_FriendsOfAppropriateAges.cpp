//
// Created by BrandonZu on 12/8/21.
//

#include "common.h"

// Runtime 76ms(>36%) | Memory Usage 37.6MB(>36%)
class Solution {
public:
    inline bool isValid(int a, int b) {
        return !(b <= 0.5 * a + 7 || b > a || (b > 100 && a < 100));
    }

    int numFriendRequests(vector<int>& ages) {
        unordered_map<int, int> cnt;
        for(int& age: ages) cnt[age]++;
        int res = 0;
        for(auto& a: cnt) {
            for(auto& b: cnt) {
                if(isValid(a.first, b.first))
                    res += a.second * (b.second - (a.first == b.first ? 1 : 0));
            }
        }
        return res;
    }
};
