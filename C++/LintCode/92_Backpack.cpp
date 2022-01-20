//
// Created by BrandonZu on 1/19/22.
//

#include "common.h"

// Beat 60%
class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A: Given n items with size A[i]
     * @return: The maximum size
     */

    // dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - v[i]] + v[i])
    int backPack(int m, vector<int> &v) {
        int n = v.size();
        vector<int> dp(m + 1, 0);
        for(int i = 1; i <= n; i++) {
            for(int j = m; j >= v[i - 1]; j--) {
                dp[j] = max(dp[j], dp[j - v[i - 1]] + v[i - 1]);
            }
        }
        return dp[m];
    }
};
