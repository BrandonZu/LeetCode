//
// Created by BrandonZu on 11/28/21.
//

#include "common.h"

// Runtime 68ms(>67%) | Memory Usage 34MB(>91%)
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> hash;
        for(char c: tasks) hash[c]++;
        int max_val = 0, cnt = 0;
        for(auto p: hash) {
            max_val = max(max_val, p.second);
        }
        for(auto p: hash) {
            if(p.second == max_val)
                cnt++;
        }
        return max((int)tasks.size(), (max_val - 1) * (n + 1) + cnt);
    }
};
