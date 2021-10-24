//
// Created by BrandonZu on 10/23/21.
//

#include "common.h"

// Runtime 336ms(>31%) | Memory Usage 28MB(>16%)
class Solution_TopDown {
public:
    int gcd(int a, int b) {
        while(a) {
            int tmp = a;
            a = b % a;
            b = tmp;
        }
        return b;
    }

    int maxScore(vector<int>& nums) {
        int l = nums.size();
        vector<vector<int>> cache(1 << l, vector<int>(l / 2 + 1));
        function<int(int, int)> dp = [&](int mask, int k) {
            if(mask == 0)
                return 0;
            if(cache[mask][k] != 0) return cache[mask][k];
            // Choose Two Numbers
            for(int i = 0; i < nums.size(); i++) {
                for(int j = i + 1; j < l; j++) {
                    if((mask & (1 << i)) && (mask & (1 << j)) != 0) {
                        cache[mask][k] = max(cache[mask][k], k * gcd(nums[i], nums[j]) + dp(mask ^ (1 << i) ^ (1 << j), k + 1));
                    }
                }
            }
            return cache[mask][k];
        };
        return dp((1 << l) - 1, 1);
    }
};

// Runtime 244ms(>53%) | Memory Usage 28MB(>16%)
class Solution_BotUp {
public:
    int gcd(int a, int b) {
        while(a) {
            int tmp = a;
            a = b % a;
            b = tmp;
        }
        return b;
    }

    int getBit(int a) {
        int count = 0;
        while(a) {
            count += a & 1;
            a >>= 1;
        }
        return count;
    }

    int maxScore(vector<int>& nums) {
        int l = nums.size();
        vector<vector<int>> dp(1 << l, vector<int>(l / 2 + 1));
        for(int mask = 0; mask < 1 << l; ++mask) {
            int c = getBit(mask);
            if(c & 1) continue;
            int k = c / 2 + 1;
            // Choose Two Numbers
            for(int i = 0; i < l; i++) {
                for(int j = i + 1; j < l; j++) {
                    if((mask & (1 << i)) == 0 && (mask & (1 << j)) == 0) {
                        int new_mask = mask | 1 << i | 1 << j;
                        dp[new_mask][k] = max(dp[new_mask][k], k * gcd(nums[i], nums[j]) + dp[mask][k - 1]);
                    }
                }
            }
        }
        return dp[(1 << l) - 1][l / 2];
    }
};

