//
// Created by BrandonZu on 11/2/21.
//

#include "common.h"

// Runtime 56ms(>92.8%) | Memorg Usage 23MB(>72%)
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int ans = 0;
        sort(pairs.begin(), pairs.end(), [&](vector<int>& a, vector<int>& b) {return a[1] < b[1];} );
        int max_end = INT_MIN;
        for(auto& p: pairs) {
            if(p[0] > max_end)
                ans++, max_end = p[1];
        }
        return ans;
    }
};

