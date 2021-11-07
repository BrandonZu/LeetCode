//
// Created by BrandonZu on 10/19/21.
//

#include "common.h"

// Runtime 40ms(>20%) | Memory Cost 13MB(>59%)
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int, int> num_map;
        for(int num: nums)
            num_map[num]++;
        int cnt = 0;
        for(auto p: num_map) {
            if(k == 0 && p.second > 1)
                cnt++;
            else if(k != 0 && num_map.find(p.first + k) != num_map.end())
                cnt++;
        }
        return cnt;
    }
};

