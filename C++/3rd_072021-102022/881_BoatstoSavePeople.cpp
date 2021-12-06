//
// Created by BrandonZu on 12/5/21.
//

#include "common.h"

// Runtime 72ms(>80%) | Memory Usage 42MB(>54%)
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int cnt = 0;
        int n = people.size();
        sort(people.begin(), people.end());
        int l = 0, r = n - 1;
        while(l < r) {
            cnt++;
            if(people[l] + people[r] <= limit) {
                l++, r--;
            }
            else {
                r--;
            }
        }
        if(l == r)
            cnt++;
        return cnt;
    }
};
