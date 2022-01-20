//
// Created by BrandonZu on 1/19/22.
//

#include "common.h"

// Beat 55%
class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A: Given n items with size A[i]
     * @param V: Given n items with value V[i]
     * @return: The maximum value
     */

    // dp[i][j]: use only first i items and up to j space of bag
    // dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - v[i]] + w[i])
    int backPackII(int m, vector<int> &A, vector<int> &V) {
        int n = A.size();
        vector<int> dp(m + 1, 0);
        for(int i = 0; i < n; i++) {
            for(int j = m; j >= A[i]; j--) {
                dp[j] = max(dp[j], dp[j - A[i]] + V[i]);
            }
        }
        return dp[m];
    }
};
