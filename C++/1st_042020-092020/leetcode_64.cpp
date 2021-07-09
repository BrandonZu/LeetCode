#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        if(n == 0) {
            return 0;
        }
        int m = grid[0].size();
        vector<int> dp(m, INT_MAX);
        dp[0] = grid[0][0];
        for(int j = 1; j < m; j++) {
            dp[j] = dp[j - 1] + grid[0][j];
        }
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < m; j++) {
                dp[j] = dp[j] + grid[i][j];
                if(j != 0) {
                    dp[j] = min(dp[j], dp[j - 1] + grid[i][j]);
                }
            }
        }
        return dp[m - 1];
    }
};

