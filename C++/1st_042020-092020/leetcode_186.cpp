#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if(n <= 1) return 0;
        if (k >= n / 2) {
            int res = 0;
            for (int i = 1; i < n; ++i)
                if (prices[i] > prices[i - 1])
                    res += prices[i] - prices[i - 1];
            return res;
        }
        vector<vector<int>> dp(k + 1, vector<int>{0, INT_MIN});
        for(int i = 0; i < n; i++) {
            for(int j = k; j >= 1; j--) {
                dp[j][0] = max(dp[j][0], dp[j][1] + prices[i]);
                dp[j][1] = max(dp[j][1], dp[j-1][0] - prices[i]);
            }
        }
        int res = 0;
        for(int i = 0; i <= k; i++)
            res = max(res, dp[i][0]);
        return res;
    }
};

int main() {
    vector<int> src = {1, 2};
    Solution tmp;
    cout << tmp.maxProfit(2, src) << endl;
    return 0;
}
