#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        if(coins.empty()) {
            if (amount == 0)
                return 1;
            else
                return 0;
        }
        else if(amount == 0)
            return 1;
        int len = coins.size();
        vector<int> dp(amount + 1, 0);
        for(int i = 0; i < amount + 1; i += coins[0])
            dp[i] = 1;
        for(int i = 1; i < len; i++) {
            for(int j = 0; j < amount + 1; j++) {
                if(j - coins[i] >= 0)
                    dp[j] += dp[j-coins[i]];
            }
        }
        return dp[amount];
    }
};

