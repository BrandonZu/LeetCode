//
// Created by BrandonZu on 1/25/22.
//

#include "common.h"

// Runtime 78ms(>33%) | Memory Usage 12.4MB(>14%)
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> dp(n, vector<int>());

        for(int i = 0; i < n; i++) {
            vector<int> maxSubset;
            for(int j = 0; j < i; j++) {
                if(nums[i] % nums[j] == 0 && dp[j].size() > maxSubset.size())
                    maxSubset = dp[j];
            }
            maxSubset.push_back(nums[i]);
            dp[i] = move(maxSubset);
        }

        vector<int> ret;
        for(auto& subset: dp) {
            if(subset.size() > ret.size())
                ret = subset;
        }
        return ret;
    }
};

// Runtime 71ms(>40%) | Memory Usage 8.7MB(>99%)
class Solution_Optimized {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> dp(n, 0);

        int maxSubsetIndex = -1, maxSubsetSize = -1;
        for(int i = 0; i < n; i++) {
            int maxSize = 0;
            for(int j = 0; j < i; j++) {
                if(nums[i] % nums[j] == 0 && dp[j] > maxSize)
                    maxSize = dp[j];
            }
            maxSize += 1;
            dp[i] = maxSize;
            if(maxSize > maxSubsetSize) {
                maxSubsetSize = maxSize;
                maxSubsetIndex = i;
            }
        }

        vector<int> ret;
        int curSize = maxSubsetSize, curTail = maxSubsetIndex;
        for(int i = maxSubsetIndex; i >= 0 && curSize > 0; i--) {
            if(nums[curTail] % nums[i] == 0 && dp[i] == curSize) {
                ret.push_back(nums[i]);
                curTail = i;
                curSize--;
            }
        }
        return ret;
    }
};
